class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int l=0,r=0,x=0; 
        for(int i=0; i<n; i++){
            switch(moves[i]){
                case 'L':l++;
                        break;
                case 'R': r++;
                        break;
                case '_' : x++;
                        break;
            }
        }

        int m= max(l-r, r-l);
        return m+x;
    }
};