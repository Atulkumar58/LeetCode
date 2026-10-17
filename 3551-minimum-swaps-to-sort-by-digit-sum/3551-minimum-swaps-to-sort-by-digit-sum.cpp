class Solution {
public:
    static int sum(int a){
        int res=0;
        while(a){
            res+= a%10;
            a/=10;
        }
        return res;
    }
    static bool custom(const int& a, const int& b){
        int x= sum(a);
        int y= sum(b);

        if(x<y) return true;
        else if(x>y) return false;
        else {
            return a<=b;
        }
    }
    int minSwaps(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]= i;
        }
        vector<int> temp= nums;
        sort(temp.begin(), temp.end(), custom);
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(mp[temp[i]] != i){
                //index i
                swap(mp[temp[i]], mp[nums[i]]);
                int x= mp[nums[i]];
                swap(nums[i], nums[x]);
                ans++;
            }
        }
        return ans;
    }
};