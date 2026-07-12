class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
        vector<int> temp= arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> m;
        int rank=1;
       if(n > 0) m[temp[0]] = rank;
        rank++;
        for(int i=1; i<n; i++){
            if(temp[i] != temp[i-1]){
                m[temp[i]]= rank++;
            }
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i]= m[arr[i]];
        }
        return ans;
    }
};