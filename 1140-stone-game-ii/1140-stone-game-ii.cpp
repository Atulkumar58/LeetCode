class Solution {
public:
    map<int, int> mp;
    int enc(int i, int m){
        return i*1000+m;
    }
    int calc(vector<int>& piles, int i, int m, bool alice){
        if(i>= piles.size()) return 0;

        if(mp.find(enc(i, m)) != mp.end()){
            if(alice) return mp[enc(i, m)];
            else return -mp[enc(i, m)];
        }
        int maxi=0;
        int sum=0;
        if(alice){ 
            maxi= INT_MIN; 
            for(int j=0; j<2*m && i+j<piles.size(); j++){
                sum+= piles[i+j];
                maxi= max(maxi, sum + calc(piles, i+j+1, max(m, j+1), !alice));
            }
        }
        else {
            maxi= INT_MAX;
            for(int j=0; j<2*m && i+j<piles.size(); j++){
                sum -= piles[i+j];
                maxi= min(maxi, sum + calc(piles, i+j+1, max(m, j+1), !alice));
            }
        }
        // cout<<i<<" "<<maxi<<endl;
        if(alice) mp[enc(i, m)]= maxi;
        else mp[enc(i, m)] = -maxi;
        return maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int sum= accumulate(piles.begin(), piles.end(), 0);
        return (sum + calc(piles, 0, 1, 1))/2;
    }
};