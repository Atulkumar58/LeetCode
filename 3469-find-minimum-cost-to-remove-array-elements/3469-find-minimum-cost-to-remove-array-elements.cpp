class Solution {
public:
    unordered_map<int, int> m;
    vector<int> nums;
    int enc(int i, int j){
        return i*1000+ j;
    }
    int rec_fun(int i, int idx){
        //i curr index
        //idx last index

        //base case 
        if(i == nums.size()-1){
            m[enc(i, idx)] = max(nums[i], nums[idx]);
            return max(nums[i], nums[idx]);
        }else if(i >= nums.size()){
            return nums[idx];
        }

        if(m.find(enc(i, idx)) != m.end()) return m[enc(i, idx)];
        int smallest = idx;
        int greatest = idx;
        for(int x= 0; x<2; x++){
            if(nums[smallest] > nums[i+x]) smallest = i+x;
            if(nums[greatest] <= nums[i+x]) greatest = i+x;
        }
        int nextidx = idx;
        for(int x=0; x<2; x++){
            if(x+i!= smallest && x+i!= greatest){
                nextidx = x+i;
            }
        }

        m[enc(i, idx)] = min(rec_fun(i+2, smallest) + nums[greatest], rec_fun(i+2, greatest)+ nums[nextidx]);
        return m[enc(i, idx)];
    }
    int minCost(vector<int>& nums) {
        this->nums= nums;
        m.clear();
        return rec_fun(1, 0);
    }
};