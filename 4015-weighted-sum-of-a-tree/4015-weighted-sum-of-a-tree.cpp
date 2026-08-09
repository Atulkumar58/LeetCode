class Solution {
public:
    vector<int> d;
    vector<vector<int>> child;
    int height(int node, int c){
        d[node]= c;

        int maxi=c;
        for(int x: child[node]){
            maxi= max(maxi, height(x, c+1));
        }
        return maxi;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n= nums.size();
        child.clear();
        child.resize(n);
        for(int i=1; i<n; i++){
            child[parent[i]].push_back(i);
        }
        d.resize(n, 0);
        int h= height(0, 1);

        long long sum=0;
        for(int i=0; i<n; i++){
            sum += ((long long)nums[i]* (h- d[i]+1));
        }
        return sum;
    }
};