class Solution {
public:
    // struct node{
    //     int maxi;
    //     int left, right;
    //     node(int maxi, int left, int right){
    //         this->maxi= maxi;
    //         this->left = left;
    //         this->right = right;
    //     }
    // };
    class segmentTree{
        int size;
        vector<int> nums;
        vector<int> st;
        int build (int idx, int left, int right){
            if(left == right){
                st[idx]= nums[left];
                return nums[left];
            }

            int maxi= INT_MIN;
            maxi= max(maxi, build(idx*2+1, left, (left + right) /2 ));
            maxi= max(maxi, build(idx*2+2, (left+right)/2 + 1, right));
            st[idx]= maxi;
            return maxi;
        }
        public:
        segmentTree(vector<int>& nums){
            this->size = nums.size();
            this->nums = nums;
            st.resize(4* size);
            build(0, 0, size-1);
        }

        bool query(int idx, int left, int right, int num){
            if(st[idx] < num) return false;
            if(left == right) {
                st[idx]=0;
                return true;
            }

            bool rv=query(idx*2+1, left, (left+right)/2, num);
            if(!rv) rv= query(idx*2+2, (left+right)/2+1, right, num);
            st[idx]= max(st[idx*2+1], st[idx*2+2]);
            // cout<<idx<<" "<<st[idx]<<endl;
            return rv;
        }
    };

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        segmentTree* s= new segmentTree(baskets);
        int ans=0;
        for(int i: fruits){
            if(!s->query(0, 0, baskets.size()-1, i)){
                ans++;
            }
            // cout<<endl<<endl;
        }
        return ans;
    }
};