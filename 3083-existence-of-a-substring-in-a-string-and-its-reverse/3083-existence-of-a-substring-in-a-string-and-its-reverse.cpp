class Solution {
public:
    bool isSubstringPresent(string s) {
        bitset<1024> seen;
        for (int i = 0; i < ssize(s) - 1; ++i)
            seen[((s[i] & 0x1f) << 5) | (s[i + 1] & 0x1f)] = true;
        for (int i = 0; i < ssize(s) - 1; ++i)
            if (seen[((s[i + 1] & 0x1f) << 5) | (s[i] & 0x1f)]) return true;
        return false; 
    }
};