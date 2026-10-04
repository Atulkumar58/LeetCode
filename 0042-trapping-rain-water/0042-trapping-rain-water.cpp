class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        int l=height[0], r= height[n-1];
        // int temp= min(l, r);
        bool left;
         if(l<=r){
                left=1;
            }else{
                left=0;
            }
        while (i <= j) {
            if(left ){
                if(l>=height[i]){
                ans+= (l-height[i]);
                i++;
                }else{
                   l=height[i];
                    i++; 
                  
                    if(l<=r) left=1;
                     else  left=0; 
                }
            }
            if(left == false){
                if(r>=height[j]){
                    ans+=(r- height[j]);
                }else{
                    r= height[j];
                   
                    if(l<=r) left=1;
                     else  left=0;
                }
                j--;
            }  
        }
        return ans;
    }
};