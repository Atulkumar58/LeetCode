class Solution {
public:
    vector<int> can_reach;
    bool check(vector<int>& arr, int idx){
        if(idx < 0 || idx >= arr.size()) return false;
        if(can_reach[idx] == 1){
            return false;
        }
        can_reach[idx]=1;
        if(arr[idx]== 0) return 1;
        return check(arr, idx+arr[idx]) || check(arr, idx-arr[idx]);
    }
    bool canReach(vector<int>& arr, int start) {
        can_reach= vector<int>(arr.size(), 0);
        return check(arr, start);
    }
};