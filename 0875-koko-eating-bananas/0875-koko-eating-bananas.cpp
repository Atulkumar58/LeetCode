class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k= 0;
        for(int i: piles) k= max(k, i);
        int i=1, j= k;
        while(i <= j){
            int mid= (i+j)/2;
            long long time=0;
            for(int i: piles){
                time+= ((i-1)/mid) + 1;
            }

            if(time  <= h){
                j= mid-1;
            }
            else i=mid+1;
        }
        return i;
    }
};