class Solution {
public:
    class SegmentTree{
    public:
        vector<int> st; // stores index of maximum
        vector<int> nums;
        void print(){
            for(int i: st) cout<<i<<" ";
        }
        void build(int idx, int i, int j){
            if(i==j){
                st[idx]= i;
                return;
            }

            int mid= (i+j)/2;
            build(idx*2+1, i, mid);
            build(idx*2+2, mid+1, j);

            if(nums[st[idx*2+1]] < nums[st[idx*2+2]]){
                st[idx]= st[idx*2+2];
            }
            else{
                st[idx]= st[idx*2+1];
            }
        }
        SegmentTree(vector<int>& nums){
           st.resize(4*nums.size());
            this->nums=nums;
            build(0, 0, nums.size()-1);
        }
        int left, right;
        int query(int idx, int i, int j){
            if(j < right) return -1;
            if(i==j){
                if(i== right){
                    if(nums[left] < nums[right] || left == right){
                        return st[idx];
                    }return -1;
                }
                else{
                    if(nums[st[idx]] > max(nums[left], nums[right])) return st[idx];
                    return -1;
                }
                
            }
            if(nums[st[idx]] < max(nums[left], nums[right])) return -1;
            
            // if(i==j){
            //     if(nums[st[idx]] >= max(nums[left], nums[right])) return st[idx];
            // }

            int mid= (i+j)/2;
            int t=query(2*idx+1, i, mid);
            if(t!= -1) return t;
            return query(2*idx+2, mid+1, j);
        }
    };
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegmentTree st(heights);
        int n= heights.size();
        vector<int> ans;
        // st.print();
        for(auto& i: queries){
            st.left= min(i[0], i[1]);
            st.right= max(i[0],i[1]);
            ans.push_back(st.query(0, 0, n-1));
        }
        return ans;
    }
};