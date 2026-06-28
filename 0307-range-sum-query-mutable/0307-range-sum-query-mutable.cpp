class NumArray {
public:
    vector<int> segmentTree;
    vector<int> nums;
    int buildTree(int idx, int left, int right){
        if(left == right){
            segmentTree[idx]= nums[left];
            return nums[left];
        }

        int rv= buildTree(idx*2+1, left, (left+right)/2) + buildTree(idx*2+2, (left+right)/2 +1, right);
        segmentTree[idx]= rv;
        return rv;
    }
    NumArray(vector<int>& nums) {
        int n= nums.size();
        this->nums= nums;
        segmentTree=vector<int>(4*n, 0);
        buildTree(0, 0, n-1);
    }
    void updateTree (int idx, int diff, int i, int left, int right){
        // if(left > right) return;
        if(idx < left || idx > right) return;

        segmentTree[i] += diff;
        if(left == right) return;
        updateTree(idx, diff, 2*i+1, left, (right+left)/2);
        updateTree(idx, diff, 2*i+2, (left+right)/2 +1, right);
    }
    void update(int index, int val) {
        int diff= val- nums[index];
        nums[index] = val;
        updateTree(index, diff, 0, 0, nums.size()-1);
    }
    int query(int idx, int l, int r, int left, int right){
        if(left > r || right < l) return 0;
        if(l>= left && r<= right) {
            return segmentTree[idx];
        }

        return query(idx*2+1, l, (r+l)/2, left, right) + query(idx*2+2, (l+r)/2+1, r, left,right);
    }
    int sumRange(int left, int right) {
        return query(0, 0, nums.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */