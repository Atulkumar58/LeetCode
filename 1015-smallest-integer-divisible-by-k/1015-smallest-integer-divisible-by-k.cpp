class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int rem = 0;
        unordered_map<int, bool> vis;
        int count=0;
        while(vis[rem] == false){
            vis[rem]= true;

            rem= (rem*10+1)%k;
            count++;
            if(rem==0){
                return count;
            }
        }
        return -1;
    }
};