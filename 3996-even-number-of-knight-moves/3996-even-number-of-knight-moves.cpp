class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int a= abs(start[1]-start[0]);
        int b= abs(target[1]-target[0]);
        if(a%2 == b%2) return 1;
        return 0;
    }
};