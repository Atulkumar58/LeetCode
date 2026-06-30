class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.length();

        int i=0, j=0;
        vector<int> count(3, 0);
        int ans=0;
        while(j < n){
            if(count[0] && count[1] && count[2]){
                ans+= (n- (j)+1);
                count[s[i]-'a']--;
                i++;
            }else{
                count[s[j]-'a']++;
                j++;
            }
            // cout<< i << " "<<j<<" "<<ans<<endl;
        }
        while(count[0] && count[1] && count[2]){
                ans+= (n- (j)+1);
                count[s[i]-'a']--;
                i++;
            }
        return ans;
    }
};