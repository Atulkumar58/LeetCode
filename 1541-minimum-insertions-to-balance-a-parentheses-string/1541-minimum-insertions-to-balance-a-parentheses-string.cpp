class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        int counter=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i] =='('){
                counter++;
            } else{
                if(i+1 <n && s[i+1]==')'){
                    counter--;
                    i++;
                }
                else{
                    ans++;
                    counter--;
                }
            }

            if(counter < 0){
                ans++;
                counter=0;
            }
            // cout<<ans<<" ";
        }

        ans+= (2*counter);
        return ans;
    }
};