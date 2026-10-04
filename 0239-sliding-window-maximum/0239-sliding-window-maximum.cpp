class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //double ended queue
        deque<pair<int, int>> dq;
        for(int i=0; i< k-1; i++){
                while(!dq.empty() && dq.back().first <= nums[i]){
                    // cout<<"pop"<<dq.back().first<<endl;
                    dq.pop_back();} 
                dq.push_back({nums[i], i});
                // cout<<"push"<<dq.back().first<<endl;
        }

        int i= k-1;
        vector<int> ans;
        while(i < nums.size()){
            while(!dq.empty() && dq.back().first <= nums[i]){
                // cout<<"pop"<<dq.back().first<<endl;
                dq.pop_back();
                }
            dq.push_back({nums[i], i});
            // cout<<nums[i]<<" "<<dq.back().first<<endl;
            // cout<<"push"<<dq.back().first<<endl;

            while(!dq.empty() && dq.front().second + k <= i) dq.pop_front();

            // cout<<dq.front().first <<" "<<dq.front().second<<endl;
            ans.push_back(dq.front().first);
            i++;
        }       
        return ans;   
    }
};