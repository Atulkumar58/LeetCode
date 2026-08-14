class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n= nums.size();
        vector<int> start(n), end(n);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            int v= i;
            while(!st.empty()){
                pair<int, int> p= st.top();
                if((p.first | nums[i]) == nums[i] && p.first != nums[i]){
                    v= p.second;
                    st.pop();
                }
                else break;
            }
            start[i]= v;
            st.push({nums[i], v});
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            int v= i;
            while(!st.empty()){
                pair<int, int> p= st.top();
                if((p.first | nums[i]) == nums[i]){
                    v= p.second;
                    st.pop();
                }
                else break;
            }
            end[i]= v;
            st.push({nums[i], v});
        }
        // for(int i: start) cout<<i<<" "; cout<<endl;
        // for(int i: end) cout<<i<<" ";

        long long ans=0;
        for(int i=0; i<n; i++){
            ans+= (long long)(i-start[i]+1) * (end[i]-i+1);
        }
        return ans;
    }   
};