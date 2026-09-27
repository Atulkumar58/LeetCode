class Solution {
public:
    class Node{
    public:
        bool end;
        vector<Node*>next;
        Node(){
            end= false;
            next=vector<Node*>(26, NULL);
        }
    };
    void build(Node* node, string& s, int idx){
        if(idx >= s.length()){
            node->end=1;
            return ;
        }
        int ch= s[idx]-'a';
        if(!node->next[ch]) node->next[ch]= new Node();
        build(node->next[ch], s, idx+1);
    }
    string ans;
    void checkLonger(string temp){
        if(temp.length() > ans.length()) ans= temp;
        else if(temp.length() == ans.length()){
            for(int i=0; i<ans.length(); i++){
                if(ans[i] < temp[i]){
                    return;
                }
                else if(ans[i] > temp[i]){
                    ans= temp;
                    return;
                }
            }
        }
    }
    void longest(Node* node, string temp){
        checkLonger(temp);

        for(int i=0; i<26; i++){
            if(node->next[i] && node->next[i]->end){
                char ch= 'a'+i;
                longest(node->next[i], temp+ch);
            }
        }
    }
    string longestWord(vector<string>& words) {
        Node* root= new Node();
        for(string& s: words){
            build(root, s, 0);
        }
        ans="";
        longest(root, "");
        return ans;
    }
};