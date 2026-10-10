class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n= nums1.size();
        long long changes= k1+k2;
        vector<int> diff(n);
        int maxi=0;
        for(int i=0;i<n; i++){
            diff[i]= abs(nums1[i]- nums2[i]);
            maxi= max(maxi, diff[i]);
        } 

        int i=0, j= maxi;
        // int ans= INT_MAX;
        while(i <= j){
            int mid= (i+j)/2;
            long long count=0;
            // int sum=0;
            for(int i: diff){
                if(i > mid){
                    count+= i-mid;
                    // sum+= ((i-mid)*(i-mid));
                } 
                // else{
                //     sum+= (i*i);
                // }
            }

            if(count > changes){
                i= mid+1;
            }else{
                // ans= min(ans, sum);
                j= mid-1;
            }
        }

        //i->max value
        for(int& val: diff){
            if(val> i){
                changes-= val-i;
                val=i;
            }
        }

        long long ans=0;
        for(int& val: diff){
            if(val == i && changes && i!=0){
                val--;
                changes--;
            }
            ans+= (long long)val*val;
        }
        return ans;
    }
};