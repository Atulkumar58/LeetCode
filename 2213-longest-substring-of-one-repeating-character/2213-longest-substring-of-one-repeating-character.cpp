class Solution {
public:
    class SegmentTree{
        public:
            string s;
            vector<vector<int>> seg;
            SegmentTree(string s){
                this->s= s;
                int n= s.length();
                seg.resize(4*n, vector<int>(3));
            }

            void build(int i, int j, int idx=0){
                if(i == j){
                    seg[idx]={1,1,1};
                    return ;
                }

                int mid= (i+j)/2;
                int left= idx*2+1, right=idx*2+2;
                build(i, mid, left);
                build(mid+1, j, right);

                vector<int> temp(3);
                temp[0]= seg[left][0];
                temp[1]=max(seg[left][1], seg[right][1]);
                temp[2]= seg[right][2];

                if(s[mid] == s[mid+1]){
                    temp[1]= max(temp[1], seg[left][2] + seg[right][0]);
                    
                    if(seg[left][0] == mid-i+1){
                        temp[0]= seg[left][0]+seg[right][0];
                    }

                    if(seg[right][2] == j-mid){
                        temp[2]= seg[right][2]+ seg[left][2];
                    }
                }

                seg[idx]= temp;
                // cout<<i<<" "<<j<<" "<<temp[1]<<endl;
            }
            int q_idx, ch;
            void query(int i, int j, int idx=0){
                if(q_idx < i || q_idx > j) return;
                
                if(i== j && q_idx==i){
                    s[q_idx]= ch;
                    return;
                }
                if(i== j) return;
                // cout<<i<<" "<<j<<endl;
                int mid= (i+j)/2;
                int left= 2*idx+1, right= 2*idx+2;
                query(i, mid, left);
                query(mid+1, j, right);

                seg[idx][0]= seg[left][0];
                seg[idx][1]=max(seg[left][1], seg[right][1]);
                seg[idx][2]= seg[right][2];

                if(s[mid] == s[mid+1]){
                    seg[idx][1]= max(seg[idx][1], seg[left][2] + seg[right][0]);
                    
                    if(seg[left][0] == mid-i+1){
                        seg[idx][0]= seg[left][0]+seg[right][0];
                    }

                    if(seg[right][2] == j-mid){
                        seg[idx][2]= seg[right][2]+ seg[left][2];
                    }
                }

            }
    };
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int n= s.length();
        st.build(0, n-1);
        vector<int> ans;
        int q= queryCharacters.size();
        for(int i=0; i<q; i++){
            st.q_idx= queryIndices[i];
            st.ch=queryCharacters[i];
            st.query(0,n-1);
            ans.push_back(st.seg[0][1]);
        }
        return ans;
    }
};