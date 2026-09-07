class Solution {
public:
    bool check(unordered_map<int, int> & m, int k){
        int ma=0;
        int sum=0;
        for(auto i: m){
            sum+= i.second;
            ma= max(ma, i.second);
        }
        if(sum-ma <= k)return true;
        return false;
    }
    int characterReplacement(string s, int k) {
        //sliding window
        int ans=0;
        int i=0, j=1;
        unordered_map<int, int> m;
        m[s[0]-'A']=1;
        while(j <= s.length()){
            if(check(m, k)){
                //increase size
                ans= j-i;
                m[s[j]-'A']++;
                j++;
            }
            else{
                //slide
                m[s[i++]-'A']--;
                m[s[j++]-'A']++;
            }
        }
        return ans;
    }
};