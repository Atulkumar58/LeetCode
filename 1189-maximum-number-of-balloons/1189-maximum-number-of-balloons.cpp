class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> a(26, 0);
        for(char c: text){
            a[c-'a']++;
        }
        int ans= INT_MAX;
        ans= min(ans, a[1]);
        ans= min(ans, a[0]);
        ans= min(ans, a['l'-'a']/2);
        ans= min(ans, a['o'-'a']/2);
        ans= min(ans, a['n'-'a']);
        // ans= min(ans, a['s'-'a']);
        return ans;
    }
};