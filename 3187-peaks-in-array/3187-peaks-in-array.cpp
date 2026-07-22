class Solution {
public:
    vector<int> stree;
    vector<int> peaks;
    void build(int idx, int i, int j){
        if(i == j){
            stree[idx] = peaks[i];
            return ;
        }
        int mid= (i+j)/2;
        build(idx*2+1, i, mid);
        build(idx*2+2, mid+1, j);

        stree[idx]= stree[idx*2+1]+stree[idx*2+2];
    }
    int id;
    void update(int idx, int i, int j){
        if(i==j && id==i){
            stree[idx]=peaks[i];
            return;
        }
        if(id > j || id < i){
            return;
        }

        int mid= (i+j)/2;
        update(idx*2+1, i, mid);
        update(idx*2+2, mid+1, j);

        stree[idx]= stree[idx*2+1]+stree[idx*2+2];
    }
    int qi, qj;
    int query(int idx, int i, int j){
        if(i>=qi && j<=qj) return stree[idx];

        if(qj < i || qi > j) return 0;
        int mid= (i+j)/2;
        return query(idx*2+1, i, mid) + query(idx*2+2, mid+1, j);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        peaks.resize(n, 0);
        for(int i=1; i<n-1; i++){
            if(nums[i]> nums[i-1] && nums[i]>nums[i+1])peaks[i] = 1;
        }
        // for(int i: peaks) cout<<i<<" ";
        stree.resize(4*n);
        //build
        build(0, 0, n-1);
        // for(int i: stree) cout<<i<<" ";
        int q= queries.size();
        vector<int> ans;
        for(int i=0; i<q; i++){
            if(queries[i][0] == 1){
                qi= queries[i][1]+1, qj= queries[i][2]-1;
                ans.push_back(query(0, 0, n-1));
            }
            else{
                nums[queries[i][1]] = queries[i][2];
                int index= queries[i][1];
                for(int j=-1; j<2; j++){
                    int newi= index+j;
                    if(newi > 0 && newi< n-1){
                        //check peak
                        if(nums[newi] > nums[newi-1] && nums[newi] > nums[newi + 1]){
                            if(peaks[newi] == 0){
                                peaks[newi] = 1;
                                id = newi;
                                update(0, 0, n-1);
                            }
                        }else{
                            if(peaks[newi] == 1){
                                peaks[newi]= 0;
                                id= newi;
                                update(0, 0, n-1);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};