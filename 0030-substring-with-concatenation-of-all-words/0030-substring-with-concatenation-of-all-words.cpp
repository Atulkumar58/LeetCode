class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n= s.length();
        map<string, int> st;
        for(int i=0; i<words.size(); i++){
            st[words[i]]++;
        }

        int size= words[0].length();
        int count= words.size();
        vector<int> ans;
        map<string, int> hash;
        for(int i=0; i<size; i++){
            int f=0;
            hash.clear();
            int x=i, y=i;
            while(y< n){
                string temp=s.substr(y, size);
                if(st.find(temp) == st.end()){
                    hash.clear();
                    y+=size;
                    x=y;
                    continue;
                }
                if(hash[temp] < st[temp]){
                    hash[temp]++;
                    y+= size;
                }
                else{
                    hash[s.substr(x, size)]--;
                    x+= size;
                }

                if(y-x == count*size){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};