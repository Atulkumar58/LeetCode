class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int digit=1;
        // for(int i=8; i>=0; i--){
        //     if(int(low / pow(10, i)) != 0){
        //         // cout<<low<<" "<<pow(10, i) << low/pow(10, i)<<endl;
        //         digit= (low/ pow(10, i));
        //         // cout<<digit<<" ";
        //         break;
        //     }
        // }
        // cout<<digit<<endl;
        for(int i= digit; i<10; i++){
            int num= 0;
            for(int j= i; j<10; j++){
                num*=10;
                num+= j;
                if(num <= high && num>= low){
                    ans.push_back(num);
                    // cout<<num <<" "<<i <<" "<<j<<endl;
                }
                else if(num > high) break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};