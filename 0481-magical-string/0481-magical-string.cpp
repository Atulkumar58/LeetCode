class Solution {
public:
    int magicalString(int n) {
        vector<int> s={1, 2, 2};
        if (n <= 3) return 1;

        int i=2;
        int ans=1;
        while(s.size() < n){
            int t= 3-s.back();
            for(int x=0; x<s[i]; x++){
                s.push_back(t);
                if(t==1 && s.size()<= n) ans++;
            } 
            i++;
        }
        return ans;
    }
};