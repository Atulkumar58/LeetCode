class Solution {
public:
    class node{
        public:
        bool bit=false;
        node* set;
        node* unset;
        node(bool x){
            bit= x;
            this->unset= this->set= NULL;
        }
    };

    void insert(int num, node* head){
        int mask = 1<<30;
        for(int i=0; i <31; i++){
            if(num & mask){
                //set bit
                if(head->set == NULL){
                    node* temp= new node(1);
                    head->set= temp;
                }
                head= head->set;
            }
            else {
                // 0 bit
                if(head->unset == NULL){
                    node* temp= new node(0);
                    head->unset = temp;
                }
                head= head->unset;
            }
            mask >>= 1;
        }
    }
    int query(node*head, int num){
        int mask= 1<<30;
        int ans=0;
        for(int i=0; i<31; i++){
            if(num & mask){
                if(head-> unset){
                    ans+= mask;
                    head= head->unset;
                }
                else{
                    head= head->set;
                }
            }else{
                if(head -> set){
                    ans+= mask;
                    head= head->set;
                }else{
                    head= head->unset;
                }
            }
            mask>>=1;
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        //we have to use trie with bit 
        // for every integer we have to 
        node* head= new node(false);
        for(int i: nums){
            insert(i, head);
        }

        int ans= 0;
        for(int i: nums){
            int t= query(head, i);
            ans= max(ans, t);
            // cout<<i<<" "<<t<<endl;
        }
        return ans;
    }
};