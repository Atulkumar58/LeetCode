class Solution {
public:
    pair<int, int> add(pair<int, int>a, pair<int, int>b){
        return {(a.first*b.second+ a.second*b.first), b.second*a.second};
    }
    pair<int, int> sub(pair<int, int>a, pair<int, int>b){
        return {(a.first*b.second- a.second*b.first), b.second*a.second};
    }
    pair<int, int> mul(pair<int, int> a, pair<int, int> b){
        return {a.first*b.first, a.second*b.second};
    }
    pair<int, int> div(pair<int, int> a, pair<int, int> b){
        return {a.first*b.second, a.second*b.first};
    }

    vector<int> cards;
    vector<bool> vis;
    bool check(vector<pair<int,int>> p){
        // for(auto i: p){
        //     cout<<i.first<<" "<<i.second<<"   ";
        // }cout<<endl;
        int n= p.size();
        if(n==1){
            if(p[0].second!= 0 && p[0].first == p[0].second*24) return 1;
            return 0;
        }
        vector<pair<int,int>> temp;
        for(int i=1; i<n;i++){
            temp.push_back(p[i]);
        }

        for(int i=0; i<n-1; i++){
            temp[i]= add(p[i], p[i+1]);
            if(check(temp)) return 1;
            temp[i]= sub(p[i], p[i+1]);
            if(check(temp)) return 1;
            temp[i]= mul(p[i], p[i+1]);
            if(check(temp)) return 1;
            temp[i]= div(p[i], p[i+1]);
            if(check(temp)) return 1;
            // cout<<endl;
            temp[i]= p[i];
        }
        return 0;
    }
    bool buildperm(vector<int>& p){
        if(p.size()==4){
            vector<pair<int, int>> temp;
            for(int i: p){
                temp.push_back({i, 1});
            }
            return check(temp);
        }
        for(int i=0;i<4;i++){
            if(!vis[i]){
                vis[i]=1;
                p.push_back(cards[i]);
                    if(buildperm(p)) return 1;
                p.pop_back();
                vis[i]=0;
            }
        }
        return 0;
    }
    bool judgePoint24(vector<int>& cards) {
        this->cards= cards;
        vis.resize(4, 0);
        // vector<pair<int, int>> p{{6,1},{1,1},{6,1},{8,1}};
        vector<int> p;
        // cout<<check(p);
        return buildperm(p);
        // return 0;
    }
};