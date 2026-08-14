class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> freq(101,0);
        for(auto& i: logs){
            freq[i[0]- 1950]++;
            freq[i[1] - 1950]--;
        }

        int maxi=0, year=0;
        int sum=0;
        for(int i=0; i<=100; i++){
            sum+= freq[i];
            if(sum > maxi){
                maxi= sum;
                year= 1950+i;
            }
        }
        return year;
    }
};