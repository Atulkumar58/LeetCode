class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m= grid.size(), n= grid[0].size();
        vector<int> arr(m*n);
        for(int i=0; i<m*n; i++){
            arr[i]= grid[i/n][i%n];
            if(i!=0){
                if(arr[i]%x != arr[i-1]%x) return -1;
            }
        }
        sort(arr.begin(), arr.end());
        int median= arr[m*n/2];
        
        int ans=0;
        for(int i: arr){
            ans+= abs(i-median);
        }
        return ans/x;
    }
};