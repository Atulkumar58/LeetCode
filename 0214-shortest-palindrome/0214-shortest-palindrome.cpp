class Solution {
public:
    string shortestPalindrome(string s) {
        //KMP
        int n= s.length();
        if(n==0) return"";
        vector<int> pre(n);
        int j= 0;
        pre[0]= 0;
        for(int i=1; i<n; i++){
            if(s[i]!= s[j] && j==0) pre[i]=0;
            else if(s[i]==s[j]){
                j++;
                pre[i]=j;
            }
            else{
                while(s[i] != s[j] && j>0){
                    j= pre[j-1];
                }
                // cout<<j<<"j ";
                if(j<0 || s[i]==s[j]){
                    j++;
                    pre[i]=j;
                }
                else pre[i]=0;
            }
            // cout<<pre[i]<<" ";
        }
        // cout<<endl;
        //algorithm
        string temp= s;
        reverse(temp.begin(), temp.end());
        j=0;
        int i=0;
        while(i < n){
            if(s[j] == temp[i]){
                i++, j++;
            }
            else{
                // cout<<i<<"->";
                // cout<<temp[i]<<" ";
                while(j>0 && s[j] != temp[i]){
                    // cout<<j<<" ";
                    // cout<<s[j]<<"  ";
                    j= pre[j-1];
                }
                // cout<<j<<" "<<endl;
                if(s[j]== temp[i]){
                    j++, i++;
                }
                else{
                    i++;
                }
            }
        }
        // cout<<j<<endl;
        while(j<n){
            temp+= s[j++];
        }
        return temp;
    }
};