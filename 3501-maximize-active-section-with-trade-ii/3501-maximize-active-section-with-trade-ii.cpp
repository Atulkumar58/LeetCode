class Solution {
public:
    vector<int> stree;
    vector<pair<int, int>>length;
    void build(int si, int i, int j){
        if(j == -1) return ;
        if(i== j){
            stree[si]=0;
            return;
        }
        if(i+1 == j){
            stree[si]= length[j].second- length[j].first + length[i].second- length[i].first + 2;
            return;
        }

        int mid= (i+j)/2;
        build(si*2+1, i, mid);
        build(si*2+2, mid, j);
        stree[si]= max(stree[si*2+1], stree[si*2+2]);
    }
    int qi, qj;
    int query(int si, int i, int j){
        if(si >= stree.size()) return 0;
        //1
        if(length[i].first >= qi && length[j].second <= qj){
            return stree[si];
        }
        
            if(stree[si] == 0) return 0;

            int mid= (i+j)/2;
            int ans= 0;
            if(qi <= length[mid].second){
                ans= max(ans, query(si*2+1, i, mid));
            }
            if(qj >= length[mid].first){
                ans= max(ans, query(si*2+2, mid, j));
            }
            // cout<<si<< " "<<ans<<" ";
        return ans;
    }
    int bs(int idx){
        int s=0, e= length.size()-1;

        while(s <= e){
            int mid= (s+e)/2;

            if(idx >= length[mid].first && idx <= length[mid].second){
                return mid;
            }
            else if(idx <= length[mid].first){
                e=mid-1;
            }else s= mid+1;
        }
        
        return -1;
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        //prefix sum already 1
        int n= s.length();
        vector<int> pre(n);
        // vector<pair<int, int>> length;
        length.clear();
        int sum=0;
        for(int i=0; i<n; i++){
            if(s[i] =='1') sum++;
            else {
                if(i == 0 || s[i-1] == '1'){
                    length.push_back({i, i});
                }
                length.back().second = i;
            }
            pre[i] = sum;
        }
        stree.clear();
        int m= length.size();
        stree.resize(4*m);
        build(0, 0, m-1);

        vector<int>ans;

        for(int i=0; i<queries.size(); i++){
            qi= queries[i][0], qj= queries[i][1];
            int temp= query(0, 0, m-1);

            int l= pre[n-1];

            int a=-1, b=-1;
            if(s[qi] == '0'){
                a= bs(qi);
            }
            if(s[qj] == '0'){
                b= bs(qj);
            }
            // cout<<temp<<" ";
            if(a != -1){
                int c = length[a].second - qi + 1;
                if(a+1 < length.size() && qj >= length[a + 1].first){
                    if(qj >= length[a + 1].second){
                        c+= length[a+1].second -length[a+1].first +1;
                    }else{
                        c+= qj - length[a+1].first +1;
                    }
                    temp= max(temp, c);
                }
            }

            if(b!= -1){
                int c= qj -length[b].first+1;
                if(b-1 >= 0 && qi <= length[b-1].second){
                    if(qi <= length[b-1].first){
                        c+= length[b-1].second -length[b-1].first + 1;
                    }else{
                        c+= length[b-1].second -qi+1;
                    }
                    temp= max(temp, c);
                }
            }
            // cout<<temp <<" "<<l<<endl;
            ans.push_back(temp + l);
        }
        return ans;
    }
};