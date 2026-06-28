class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        int value= 1;
        for(int i=0; i<n; i++){
            if(arr[i] < value){
                value= arr[i];
            }
            value++;
        }
        return value - 1;
    }
};