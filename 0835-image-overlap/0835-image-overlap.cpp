class Solution {
public:
    vector<vector<int>> img1, img2;
    int calc(int i, int j){
        int res=0;
        for(int x=0; x<img1.size(); x++){
            for(int y=0; y<img1[0].size(); y++){
                if(x+i < 0 || x+i >= img1.size()) continue;
                if(y+j < 0 || y+j >= img1[0].size()) continue;
                if(img1[x][y]==0) continue;
                if(img1[x][y] == img2[x+i][y+j]){
                    res++;
                }
            }
        }
        return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        this->img1= img1, this->img2= img2;
        int n= img1.size();
        int m= img2.size();
        int res=0;
        for(int i=-n+1; i<n; i++){
            for(int j=-m+1; j<m; j++){
                res= max(res, calc(i, j));
            }
        }
        return res;
    }
};