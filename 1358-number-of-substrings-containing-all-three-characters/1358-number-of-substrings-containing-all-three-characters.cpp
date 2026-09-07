class Solution {
public:
    bool check(vector<int> &arr){
        if(arr[0]>0 && arr[1]>0 && arr[2]>0)
        return true;
        return false;
    }
    void enter(vector<int>& arr, char s){
        switch(s){
            case 'a': arr[0]++;
                break;
            case 'b': arr[1]++;
                break;
            case 'c': arr[2]++;
                break;
        }
    }
    void del(vector<int>& arr, char s){
        switch(s){
            case 'a': arr[0]--;
                break;
            case 'b': arr[1]--;
                break;
            case 'c': arr[2]--;
                break;
        }
    }
    int numberOfSubstrings(string s) {
        vector<int> arr(3, 0);
        int n= s.length();
        int j=0;
        int ans=0;
        for(int i=0; i<n; i++){
            while(!check(arr) && j<n){
                enter(arr, s[j]);
                j++;
            }
            if(check(arr))
            ans+= (n-j+1);
            // cout<<ans<<" "<<i<< " "<<j<<endl;
            del(arr, s[i]);
        }
        return ans;
    }
    
};