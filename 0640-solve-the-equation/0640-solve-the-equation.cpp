class Solution {
public:
    vector<int> pres(string equation, int idx){
        int l=0;
        int i=idx;
        bool pos=1;
        int var=0;
        bool var_tr=0;
        int x=0;
        while(equation[i] != '=' && i<equation.length()){
            if(equation[i] <='9' && equation[i] >= '0'){
                var= var*10+(equation[i]-'0');
                var_tr=1;
            }
            else if(equation[i] == '-'){
                // cout<<var<<" ";
                l+= (pos)? var : -var;
                var_tr=0;
                var= 0;
                pos=0;
            }
            else if(equation[i] == '+'){
                // cout<<var<<" ";
                var_tr=0;
                l+= (pos)? var : -var;
                var= 0;
                pos= 1;  
            }
            
            else if(equation[i] == 'x'){
                if(!var_tr && var == 0){
                    if(pos) x++;
                    else x--;
                } 
                x+= ((pos==1)? var : -var);
                // cout<<"X: "<<x<<endl;
                var=0;
            }
            i++;
        }
        l+= (pos)? var : -var;
        // cout<<i<<endl;
        return {x, l, i};
    }
    string solveEquation(string equation) {
        vector<int> a= pres(equation, 0);
        vector<int> b= pres(equation, a[2]+1);
        // cout<<a[0] <<" "<< a[1]<<endl;
        // cout<<b[0]<<" "<<b[1]<<endl;
        if(a[0]==b[0]){
            if(a[1] == b[1]) return "Infinite solutions";
            else return "No solution";
        } 
        int ans=(a[1]- b[1])/(b[0]-a[0]);
        return "x="+ to_string(ans);
    }
};