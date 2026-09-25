class NumArray {
public:
    vector<int> nums;
    vector<int> st;
    int build(int idx, int i, int j){
        if(i==j){
            st[idx]= nums[i];
            return st[idx];
        }
        int mid= (i+j)/2;
        int v= build(2*idx+1, i, mid);
        v+= build(2*idx+2, mid+1, j);
        st[idx]= v;
        return v;
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n= nums.size();
        st.resize(4*n);
        build(0, 0, n-1);
    }
    int index, val;
    void up(int idx, int i, int j){
        if(i==j){
            // cout<<idx<<" "<<i<<" "<<j<<endl;
            st[idx]= val;
            nums[index]= val;
            return;
        }

        int mid= (i+j)/2;
        if(index<=mid){
            up(2*idx+1, i, mid);
        }
        else{
            up(2*idx+2, mid+1, j);
        }

        st[idx]= st[2*idx+1]+st[2*idx+2];
    }
    void update(int index, int val) {
        this->index= index, this->val= val;
        up(0, 0, nums.size()-1);
    }
    int left, right;
    int query(int idx, int i, int j){
        if(left<= i && j<=right) return st[idx];
        if(right < i || left> j) return 0;

        int mid= (i+j)/2;
        return query(2*idx+1, i, mid)+ query(2*idx+2, mid+1, j);
    }
    int sumRange(int left, int right) { 
        this->left= left, this->right= right;
        return query(0, 0, nums.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */