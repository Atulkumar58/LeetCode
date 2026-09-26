class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        queue<char> q;
        for(char ch: s){
            if(ch == ')'){
                while(!q.empty() && q.front()!='('){
                    ans+= q.front();
                    q.pop();
                }
                if(!q.empty()){
                    ans+=q.front();
                    q.pop();

                    q.push(ch);
                }
            }
            else{
                q.push(ch);
            }
        }

        while(!q.empty()){
            if(q.front() =='(') {
                q.pop();continue;
            }
            ans+= q.front();
            q.pop();
        }
        return ans;
    }
};