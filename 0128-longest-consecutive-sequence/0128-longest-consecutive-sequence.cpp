class Solution {
public:
    unordered_map<int, int> m;
    int ultimateparent(int node){
        if(m[node] == node){
            return node;
        }
        int p= ultimateparent(m[node]);
        m[node]= p;
        return p;
    }
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        int length=0;
        for(int i=0; i<n; i++){
            if(m.find(nums[i]-1) == m.end()){
                //not found
                m[nums[i]]=nums[i];
            }else{
                int p= ultimateparent(nums[i]-1);
                m[nums[i]]= p;
            }

            if(m.find(nums[i] + 1) != m.end()){
                m[nums[i]+1]= m[nums[i]];
            }
        }

        for(int i: nums){
            length= max(length, i-ultimateparent(i)+1);
        }
        return length;
    }
};