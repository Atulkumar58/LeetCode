class Solution {
public:
    int longestValidParentheses(string s) {
        unordered_map<int, int> mp;
        int sum=0;
        int n= s.length();
        int l=0;
        mp[0]=-1;
        for(int i=0; i<n; i++){
            if(s[i] =='(') sum++;
            else{
                mp.erase(sum);
                sum--;
            }

            if(mp.find(sum) != mp.end()){
                l= max(l, i- mp[sum]);
            }
            else{
                mp[sum]= i;
            }
        }
        return l;
    }
};