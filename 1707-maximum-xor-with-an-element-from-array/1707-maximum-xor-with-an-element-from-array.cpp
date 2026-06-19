class Solution {
public:
    class node{
        public:
            bool bit;
            int maximumelement;
            node* set;
            node* unset;
            node(bool bit){
                this->bit= bit;
                this->maximumelement= INT_MAX;
                this->set= this->unset= NULL;
            }
    };
    void insert(node* head, int n){
        int mask= 1<<30;
        for(int i=0; i<31; i++){
            if(n & mask){
                //set 
                if(head->set == NULL){
                    node* temp= new node(1);
                    head->set= temp;
                }
                head= head->set;
                head-> maximumelement = min(head->maximumelement, n);
            }else{
                //unset
                if(head->unset == NULL){
                    node* temp= new node(0);
                    head->unset= temp;
                }
                head= head->unset;
                head->maximumelement = min(head->maximumelement, n);
            }
            mask >>= 1;
        }
    }
    int query (node* head, int val, int m){
        int ans=0;
        int mask= 1<<30;
        for(int i=0; i<31; i++){
            if(mask & val){
                //set
                if(head->unset && head->unset->maximumelement <= m){
                    ans+= mask;
                    head= head->unset;
                }else if(head->set && head->set->maximumelement <=m){
                    head= head->set;
                }else{
                    return -1;
                }
            }else{
                //unset
                if(head-> set && head->set->maximumelement <= m){
                        ans+= mask;
                        head= head-> set;
                }else if(head->unset && head-> unset->maximumelement <= m){
                        head= head->unset;
                }else{
                    return -1;
                }
            }
            mask >>= 1;
            // cout<<ans<<" ";
        }
        // cout<<endl;
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        node* head= new node(0);
        for(int i: nums) insert(head, i);

        
        for(int i=0; i<queries.size(); i++){
            ans.push_back(query(head, queries[i][0], queries[i][1]));
        }
        return ans;
    }
};