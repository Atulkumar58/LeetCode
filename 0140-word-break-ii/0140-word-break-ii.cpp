class Solution {
public:
    // TRIE implementation
    struct Node{
        public:
        char c;
        bool last;
        vector<Node*> alpha;
        Node(char c){
            this->c=c;
            alpha= vector<Node*>(26,0);
            last=0;
        }
    };
    Node* root;
     // for building
    void build(string str){
        Node* temp= root;
        int n= str.length();
        for(int i=0; i<n; i++){
            int t= str[i]-'a';
            if(temp->alpha[t]){
                temp = temp->alpha[t];
            }
            else{
                Node* tn= new Node(str[i]);
                temp->alpha[t]= tn;
                temp= tn;
            }
        }
        temp->last = 1;
    }
    vector<vector<string>> dp;
    vector<bool> vis;
    string s;
    void calculate(int i){
        int idx= i;
        if(idx>=s.length() || vis[i]) return;

        Node* temp= root;
        string res="";
        while(idx<s.length() && temp->alpha[s[idx]-'a']){
            res+= s[idx];
            temp= temp->alpha[s[idx]-'a'];
            if(temp->last){
                calculate(idx+1);
                if(idx+1 < s.length())
                for(string& x: dp[idx+1]){
                    dp[i].push_back(res+' '+x);
                }
            }
            idx++;
        }

        if(idx == s.length()){
            if(temp->last){
                dp[i].push_back(res);
            }
        }
        vis[i]=1;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this-> root= new Node(' ');
        int m= wordDict.size();
        for(int i=0; i<m; i++){
            build(wordDict[i]);
        }
        
        int n= s.length();
        dp.resize(n, {});
        vis.resize(n, 0);
        this->s= s;

        calculate(0);
        return dp[0];
    }
};