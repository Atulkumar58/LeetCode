class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s;
        for(int i: arr1){
            while(i){
                s.insert(i);
                i/=10;
            }
        }

        int ans=0;
        for(int i:arr2){
            while(i){
                if(s.find(i) != s.end()){
                    ans= max(ans, i);
                    break;
                }
                i/=10;
            }
        }

        int len=0;
        while(ans){
            len++;
            ans/=10;
        }
        return len;
    }
};