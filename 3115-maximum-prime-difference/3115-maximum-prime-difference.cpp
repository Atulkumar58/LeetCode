class Solution {
public:
    vector<bool>primes;
    void pre(int n){
        for(int i=2; i<=n; i++){
            for(int j= i*i; j<=n; j+=i){
                primes[j]=0;
            }
        }
    }
    int maximumPrimeDifference(vector<int>& nums) {
        primes.resize(101, true);
        primes[1]=0;
        pre(100);

        int l=-1, r=-1;
        int ans= INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(primes[nums[i]]){
                if(l==-1) l=i;
                r=i;
            }
        }
        return r-l;
    }
};