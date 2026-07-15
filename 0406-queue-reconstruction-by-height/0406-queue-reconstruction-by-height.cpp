class Solution {
public:
    // easy approach 
    // using linked list
    struct Node{
        int idx;
        Node* next;

        Node(int i){
            this-> idx= i;
            next= NULL;
        }
    };
    static bool grecustom(vector<int>a, vector<int>b){
        if(a[1] < b[1]) return true;
        if(a[1] == b[1]) {
            if(a[0] < b[0]) return 1;
        }return 0;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), grecustom);
        int n= people.size();
        if(n == 0) return {{}};
        Node* head= new Node(0);
        for(int i=1; i<n; i++){
            Node* curr= head;
            Node* prev= NULL;
            int count = 0;
            while(curr){
                // cout<<curr->idx<<" ";
                
                if(people[curr->idx][0] >= people[i][0]){
                    if(count == people[i][1]){
                        Node* temp= new Node(i);
                        temp->next= curr;
                        prev->next= temp;
                        break;
                    }
                    count++;
                }

                if(curr-> next == NULL){
                    Node* temp= new Node(i);
                    curr->next= temp;
                    break;
                }
                prev= curr;
                curr= curr->next;
            }
            // cout<<endl;
        }

        vector<vector<int>> ans;
        Node* curr= head;
        while(curr){
            ans.push_back(people[curr->idx]);
            curr= curr->next;
        }
        return ans;
    }
};