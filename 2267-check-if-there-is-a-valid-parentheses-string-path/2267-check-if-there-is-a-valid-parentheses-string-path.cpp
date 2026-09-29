class Solution {
public:
    vector<vector<char>>grid;
    unordered_map<int, bool> mp;

    int x[4]= {1, 0};
    int y[4]= {0, 1};
    int enc(int i, int j, int left){
        return left*1e4 + i*100 + j;
    }
    bool calc(int i, int j, int left){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size()) return false;

        if(mp.find(enc(i, j, left)) != mp.end()){
            return mp[enc(i, j, left)];
        }
        int l= left;
        if(grid[i][j] == '(') left++;
        else left--;
        if(left < 0) return false;
        
        if(i==grid.size()-1 && j==grid[0].size()-1 && left == 0){
            return true;
        }

        for(int idx=0; idx<2; idx++){
            if(calc(i+x[idx], j+y[idx], left)) return true;
        }
        mp[enc(i, j, l)]=false;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        this->grid= grid; 
        mp.clear();
        return calc(0, 0, 0);   
    }
};