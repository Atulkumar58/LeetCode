class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double sum=0;
        for(int i=0; i<prices.size(); i++){
            if(i < discounts.size()){
                sum+= ((double)prices[i] *(100-discounts[i])) /100;
            }else{
                sum+= prices[i];
            }
        }
        return sum;
    }
};