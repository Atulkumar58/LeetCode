class Solution {
public:
    int ans=0;
    vector<int> nums;
    void conquer(int i, int j){
        vector<int> x;
        int mid= (i+j)/2;
        int s1=i, s2= (i+j)/2+1;
        while(s1 <= mid && s2 <= j){
            if((long long)nums[s1] <= (long long)nums[s2]*2){
                s1++;
            }else{
                ans+= (mid -s1+1);
                s2++;
            }
        }

        s1=i, s2= mid+1;
        while(s1 <= mid && s2 <= j){
            if(nums[s1] <= nums[s2]){
                x.push_back(nums[s1++]);
            }else{
                x.push_back(nums[s2++]);
            }
        }

        while(s1 <= mid) x.push_back(nums[s1++]);
        while(s2 <= j) x.push_back(nums[s2++]);
        // cout<<i<<" "<<j<<endl;
        for(int idx=0; idx<x.size(); idx++){
            nums[idx + i] = x[idx];
            // cout<<nums[idx+i]<<" ";
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        // cout<<endl;
    }
    void divide( int i, int j){
        if(i == j) return;

        int mid= (i+j)/2;
        divide(i, mid);
        divide(mid+1, j);

        conquer(i, j);
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        int n= nums.size();
        this->nums = nums;
        divide(0, n-1);
        // for(int i: nums) cout<<i<<" ";
        return ans;
    }
};