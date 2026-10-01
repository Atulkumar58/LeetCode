class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> sum; //a+b -> index
        unordered_map<int, int> s; // value -> freq
        int i=0, j=0;
        int n= nums.size();
        while(j < n){
            bool poss= 1;
            //a+b = new
            if(sum.find(nums[j]) != sum.end()){
                int t= sum[nums[j]];
                if(t >= i){
                    poss=0;
                }
            }

            //new+a= b
            for(int idx= i; idx<j; idx++){
                if(s.find(nums[j] + nums[idx]) != s.end()){
                    if(s[nums[j] + nums[idx]] > 0){
                        poss= false;
                    }
                    else s.erase(nums[j] + nums[idx]);
                }
            }

            if(poss){
                s[nums[j]]++;
                for(int idx=i; idx<j; idx++){
                    int t= nums[j]+nums[idx];
                    sum[t]= max(sum[t], idx);
                }
                j++;
            }
            else{
                s[nums[i]]--;
                i++;
            }
            // cout<<i<<" "<<j<<endl;
            ans= max(ans, j-i);
        }
        return ans;
    }
};