class Solution {
public:
    int len(string& s){
        int ans=0;
        int d=0;
        for(char ch: s){
            if(ch =='(') d++;
            else d--;
            ans= max(ans, d);
        }
        return ans;
    }
    vector<int> maxDepthAfterSplit(string seq) {
        int l= len(seq);
        int depth_a= l/2;
        int n=seq.length();
        vector<int> ans(n);
        int d=0;
        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                d++;
                if(d <= depth_a){
                    ans[i]= 0;
                }
                else ans[i]=1;
            } 
            else{
                d--;
                if(d < depth_a){
                    ans[i]= 0;
                }
                else ans[i]=1;
            } 
            
        }
        return ans;
    }
};