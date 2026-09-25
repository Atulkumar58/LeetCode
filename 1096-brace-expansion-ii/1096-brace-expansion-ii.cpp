class Solution {
public:
    void join(vector<string>&a, vector<string>&b){
        if(a.size() ==0) {a=b; return;}
        set<string>s;
        for(string& x:a){
            for(string& y:b){
                s.insert(x+y);
            }
        }
        a.clear();
        for(auto i: s){
            a.push_back(i);
        }
    }
    string expression;
    vector<string> solve(int i, int j){
        // solves { }
        set<string> ans;
        vector<string> temp;
        for(int idx= i+1; idx<j; idx++){
            if(expression[idx] =='{'){
                int counter=0;
                int x=idx;
                do{
                    if(expression[x] == '{') counter++;
                    else if(expression[x]=='}') counter--;
                    x++;
                }
                while(counter!= 0);
                vector<string>t= solve(idx, x-1);
                idx =x-1;
                join(temp, t);
            }
            else if(expression[idx] <='z' && expression[idx]>='a'){
                if(temp.size()==0){
                    temp.push_back("");
                }
                for(string& s: temp){
                    s+= expression[idx];
                }
            }
            else if(expression[idx] == ','){
                for(string& s: temp){
                    ans.insert(s);
                }
                temp.clear();
            }
        }
        for(string& s: temp) ans.insert(s);

        return vector<string>(ans.begin(), ans.end());
    }
    vector<string> braceExpansionII(string expression) {
        this->expression= expression;
        int n= expression.size();
        return solve(-1, n);
    }
};