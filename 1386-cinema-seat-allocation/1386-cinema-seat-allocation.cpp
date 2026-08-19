class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int last= 0;
        int size= reservedSeats.size();
        int ans=0;
        for(int i=0; i<size; i++){
            int t= reservedSeats[i][0]- last-1;
            ans+= (t*2);
            ans+= (reservedSeats[i][1]-2)/4;
            while(i<size-1 && reservedSeats[i][0] == reservedSeats[i+1][0]){
                int t= reservedSeats[i+1][1] - reservedSeats[i][1]-1;
                if(t== 4){
                    if(reservedSeats[i][1]%2==1){
                        ans++;
                    }
                    i++;
                    continue;
                }
                ans+= (t/4);
                i++;
            }
            ans+= (10 - reservedSeats[i][1] -1)/4;
            last= reservedSeats[i][0];
            // cout<<ans<<" ";
        }
        ans+= (n-reservedSeats.back()[0])*2;
        return ans;
    }
};