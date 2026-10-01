class Solution {
public:
    const int mod= 1e9 +7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long ans=0, sum=0;
        for(int i: arr){
            sum+= i;
            if(sum < 0) sum=0;
            ans= max(ans, sum);
        }
        long long left=0; sum=0;
        for(int i: arr){
            sum+= i;
            left= max(left, sum);
        }
        long long right=0; sum=0;
        for(int i= arr.size()-1; i>=0; i--){
            sum+= arr[i];
            right= max(right, sum);
        }

        if(k==1) return ans;
        ans= max(ans, right+left + (k-2)* ((sum<0) ? 0 : sum));
        return ans % mod;
    }
};