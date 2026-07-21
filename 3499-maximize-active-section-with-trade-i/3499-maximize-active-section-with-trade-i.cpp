class Solution {
public:
    int maxActiveSectionsAfterTrade(string str) {
        int n= str.length();
        vector<int> z;
        int ans=0;
        int cz=0;
        for(int i=0; i<n; i++){
            if(str[i] == '1'){
                ans++;
                if(cz){
                    z.push_back(cz);
                    cz = 0;
                }
            }
            else cz++;
        }
        if(cz) z.push_back(cz);
        cz=0;
        // if(z.size() == 0 || z.size()==1) return ans;
        for(int i=1; i<z.size(); i++){
            cz= max(cz, z[i]+z[i-1]);
        }
        return cz + ans;
    }
};