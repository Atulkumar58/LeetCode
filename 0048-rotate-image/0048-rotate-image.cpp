class Solution {
public:
    void print(vector<vector<int>> & a, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        if(n==1){
            return;
        }
        int temp[n-1];
        // for(int j=n-1, i=0; j>=0; j--, i++){
        //     temp[i]=matrix [j][0];
        // }
        int line=0;
        
        while(line< n-1){
           
             for(int j=n-1, i=line; j>line; j--, i++){
               temp[i]=matrix [j][line];
               
              }
              print(matrix, matrix.size());
            //top
            for(int i=line; i<n-1; i++){
                swap(matrix[line][i],temp[i]);
               
            }
           
            //right
            for(int i=line; i<n-1; i++){
                swap(matrix[i][n-1],temp[i]);
            }
             

            //bottom
            for(int i=line, j=0; j<n-line-1; i++,j++){
                swap(matrix[n-1][n-j-1],temp[i]);
                
            }
 
            // left
              for(int i=line, j=0; j<n-line-1; i++, j++){
                swap(matrix[n-j-1][line], temp[i]);
            }

            n--;
            line++;
        }

      
           
        
    }
};