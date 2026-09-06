class Solution {
public:
    int ans;
    vector<int> nums;
    void conquer(int i, int j){
        int mid= (i+j)/2;

        int x= i, y= mid+1;

        while(x<=mid && y<= j){
            if((long long)nums[x] > (long long)nums[y]*2 ){
                ans+= (mid-x+1);
                y++;
            }
            else x++;
        }
        x=i, y=mid+1;
        // for(int idx=i; idx<=j; idx++) cout<<nums[idx]; cout<<endl;
        vector<int> temp;
        while(x<=mid && y<= j){
            if(nums[x] <= nums[y]){
                temp.push_back(nums[x++]);
            }
            else temp.push_back(nums[y++]);
        }
        while(x<=mid) temp.push_back(nums[x++]);
        while(y<=j) temp.push_back(nums[y++]);

        for(int x= i; x<=j; x++){
            nums[x]= temp[x-i];
            // cout<<nums[x]<<" ";
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
    }
    void divide(int i, int j){
        if(i >= j) return;
        int mid= (i+j)/2;
        divide(i, mid);
        divide(mid+1, j);
        conquer(i, j);
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        this->nums= nums;
        divide(0, nums.size()-1);
        return ans;
    }
};