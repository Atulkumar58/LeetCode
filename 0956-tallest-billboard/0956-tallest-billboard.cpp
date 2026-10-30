class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n= rods.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            map<int, int> t;
            t[rods[i]]= rods[i];
            t[-rods[i]]= rods[i];

            for(auto it: mp){
                t[it.first+ rods[i]]= max(t[it.first+ rods[i]],it.second+ rods[i]);
                t[it.first - rods[i]]= max(t[it.first - rods[i]],it.second+ rods[i]);
                t[it.first]= max(t[it.first], it.second);
            }
            mp= t;
        }

        return mp[0]/2;
    }
};