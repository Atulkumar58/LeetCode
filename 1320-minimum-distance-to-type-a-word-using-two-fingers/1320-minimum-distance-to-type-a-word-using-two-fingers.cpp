class Solution {
public:
    // memo[word_index][finger1_pos][finger2_pos]
    int memo[301][27][27];
    string s;

    // Manhattan distance on a 6-column keyboard
    int dist(int from, int to) {
        if (from == 26) return 0; // First move for any finger is free
        int r1 = from / 6, c1 = from % 6;
        int r2 = to / 6, c2 = to % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int solve(int i, int f1, int f2) {
        // Base case: typed all characters
        if (i == s.length()) return 0;
        
        // Return cached result
        if (memo[i][f1][f2] != -1) return memo[i][f1][f2];

        int charIdx = s[i] - 'A';

        // Option 1: Move Finger 1
        int moveF1 = dist(f1, charIdx) + solve(i + 1, charIdx, f2);
        
        // Option 2: Move Finger 2
        int moveF2 = dist(f2, charIdx) + solve(i + 1, f1, charIdx);

        return memo[i][f1][f2] = min(moveF1, moveF2);
    }

    int minimumDistance(string word) {
        s = word;
        memset(memo, -1, sizeof(memo));
        // Start both fingers at state 26 (off-board)
        return solve(0, 26, 26);
    }
};