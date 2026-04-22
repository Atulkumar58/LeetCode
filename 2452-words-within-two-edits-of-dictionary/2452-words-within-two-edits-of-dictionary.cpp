class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // int n= queries.size();
        vector<string> ans;
        for(string& q: queries){
            for(string& s: dictionary){
                int count=0;
                for(int j=0; j<s.length(); j++){
                    if(s[j] != q[j]) count++;
                    if(count > 2) break;
                }
                if(count <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};