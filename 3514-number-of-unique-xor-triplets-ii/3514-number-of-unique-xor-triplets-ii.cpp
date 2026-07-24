class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>s;
        unordered_set <int> ns;
        s.insert(0);
        int n= nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                s.insert(nums[i] ^ nums[j]);
            }
        }

        for(int num: s){
            for(int i=0; i<n; i++){
                ns.insert(num ^ nums[i]);
            }
        }
        return ns.size();
    }
};