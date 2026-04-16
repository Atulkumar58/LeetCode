class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n= nums.size();
        vector<int> left(n, INT_MAX);
        unordered_map<int, int> m; //value idx
        unordered_map<int, int> r;
        for(int i=0; i<n; i++){
            m[nums[i]]= i;
            r[nums[n-i-1]]= n-i-1;
        }

        for(int i=0; i<n; i++){
            int t= m[nums[i]];
            if(t != i){
                if(t > i){
                    left[i]= min(left[i],i+n-t);
                }else{
                    left[i]= min(i-t, left[i]);
                }
            }
            t= r[nums[n-i-1]];
            if(t > n-i-1){
                left[n-i-1]= min(left[n-i-1], t- n+i+1);
            }else if(t < n-1-i){
                left[n-i-1]= min(left[n-i-1], t+i+1);
            }
            m[nums[i]]=i;
             r[nums[n-i-1]]= n-i-1;
        }
        vector<int> ans;
        for(int i: queries){
            ans.push_back((left[i]==INT_MAX)? -1 : left[i]);
        }
        return ans;
    }
};