class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i=0;
        int n= words.size();
        while(i <= n/2){
            if(target == words[(i+startIndex) %n] || target== words[(startIndex-i+n) % n]){
                return i;
            }
            i++;
        }
        return -1;
    }
};