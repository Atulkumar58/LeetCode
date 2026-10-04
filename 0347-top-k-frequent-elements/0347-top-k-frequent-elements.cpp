class Solution {
public:
    class Node{
        public:
        int data;
        int count;
        Node(int a, int b){
            this->data= a;
            this-> count= b;
        }
    };
    class compare{
        public:
        bool operator()(Node* a, Node* b){
            return a->count < b->count;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) == m.end()){
                m.insert({nums[i], 1});
            }else{
                auto temp= m.find(nums[i]);
                temp-> second= temp->second+1;
            }
        }

        priority_queue<Node*, vector<Node*>, compare> minh;
        for(auto i= m.begin(); i!= m.end(); i++){
            Node* temp= new Node(i->first, i->second);
            minh.push(temp);
        }

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(minh.top()->data);
            minh.pop();
        }
        return ans;
    }
};