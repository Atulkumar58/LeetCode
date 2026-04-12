class Solution {
public:
    string word="";
    unordered_map<int, int>m;
    int enc(int i, int a, int b){
        return i*(1000)+ a*28 + b;
    }
    int dist(int a, int f){
         if(a==26 || f==26) return 0;
        return abs(a/6 - f/6) + abs(a%6 - f%6);
    }
    int minfind(int i, int a, int b){
        if(i== word.length()) return 0;

        if(m.find(enc(i, a, b)) != m.end()){
            return m[enc(i, a, b)];
        }
        int r1= dist(a, word[i]-'A')+minfind(i+1, word[i]-'A', b);
        int r2= dist(word[i]-'A', b)+minfind(i+1, a, word[i]-'A');
        
        return m[enc(i, a, b)] = min(r1,r2);
    }
    int minimumDistance(string word) {
        m.clear();
        this->word= word;
        vector<int> a={0, -1};
        return minfind(0, 26, 26);
    }
};