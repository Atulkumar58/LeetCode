class Solution {
    public int firstMatchingIndex(String s) {
        int n= s.length();
        int i=0;
        while(i <= n-i-1){
            if(s.charAt(i) == s.charAt(n-1-i)) return i;
            i++;
        }
        return -1;
    }
}