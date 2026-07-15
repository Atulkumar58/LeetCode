class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
	int y[4] = {0 , 0, 1, -1};
	int size(vector<vector<int>>& matrix, int i, int j, int num){
		matrix[i][j] = num;
		int ans=1;
		for(int idx=0; idx<4; idx++){
			int ni= i+x[idx], nj= j+y[idx];
			if(ni>=0 && nj>=0 && ni < matrix.size() && nj<matrix[0].size())
			if(matrix[i+x[idx]][j+y[idx]] == 1){
				ans+= size(matrix, i+x[idx], j+y[idx], num);
            }
        }
    return ans;
}

    int largestIsland(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();
	
        int island = 2;
        unordered_map<int, int> mp;
        int result=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    int siz= size(matrix, i, j, island);
                    mp[island] = siz;
                    result = max(result, siz+1);
                    island++;
                }
    }
    }

    if(result > n*m) return n*m;
    set<pair<int, int>> is; // 1 size 2 island
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                is.clear();
                for(int k=0; k<4; k++){
                    int ni= i+x[k], nj=j+y[k];
                    if(ni>=0 && nj>=0 && ni<m && nj<n){	
                        is.insert({mp[matrix[ni][nj]],matrix[ni][nj]});
                    }
                }
                int temp=0;
                for(auto it: is){
                    temp+= it.first;
                }
                result = max(result, temp+1);
                // cout<<endl;
            }
        }
    }
    return result;

    }
};