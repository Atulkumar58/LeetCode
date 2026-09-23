class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m= isWater.size();
        int n= isWater[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               
                if(isWater[i][j] == 1){
                    isWater[i][j]=0;
                }else if(i==0 && j==0){
                    isWater[i][j]=35421;
                    continue;
                }
                else{
                    if(i==0){
                        isWater[i][j]= isWater[i][j-1] + 1;
                    }
                    else if(j==0){
                        isWater[i][j]= isWater[i-1][j] +1;
                    }
                    else{
                        isWater[i][j]= min(isWater[i-1][j], isWater[i][j-1])+1;
                    }
                }
            }
        }
        int idxi, idxj;
        for(int i=m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){
                if((i==m-1 && j==n-1) || isWater[i][j] ==0 ){
                    continue;
                }
                int temp;
                if(i==m-1){
                    temp= isWater[i][j+1];
                }
                else if(j==n-1){
                    temp=isWater[i+1][j];
                }else{
                    temp= min(isWater[i+1][j], isWater[i][j+1]);
                }
                if(isWater[i][j] > temp+1){
                    isWater[i][j]= temp+1;
                }
            }
        }
        return isWater;
    }
};