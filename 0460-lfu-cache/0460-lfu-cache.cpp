class LFUCache {
    class Node{
    public:
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;
        Node(){
        }
        Node(int key, int value){
            this->key= key;
            this->value= value;
            freq= 0;
            this->prev= this->next= NULL;
        }
    };
public:
    unordered_map<int, Node*> mp; //key -> address
    unordered_map<int, Node*> freq; // freq-> first address
    Node* oldest;
    Node* newest;
    //delete from oldest side
    int capacity;
    int size;
    void print(){
        Node* temp= oldest->next;
        while(temp!= newest){
            cout<<"("<<temp->key<< " "<<temp->value<<" "<<temp->freq<<")";
            temp= temp->next;
        }cout<<endl;
    }
    LFUCache(int capacity) {
        this->capacity= capacity;
        this->size =0;

        oldest= new Node();
        newest= new Node();
        oldest->next= newest;
        newest->prev= oldest;
    }
    void insert(Node* node){
        if(freq[node->freq] == node){
            if(node->prev->freq == node->freq){
                freq[node->freq]= node->prev;
            }
            else{
                freq[node->freq]= NULL;
            }
        }
        node->freq++;

        Node* temp= NULL;
        if(freq[node->freq] == NULL){
            //insert at the front
            temp= freq[node->freq-1];
            if(temp==NULL){
                freq[node->freq]=node;
            }
            else{
                //remove
                node->next->prev= node->prev;
                node->prev->next= node->next;

                //add after the temp
                temp->next->prev= node;
                node->next= temp->next;
                node->prev= temp;
                temp->next= node;

                freq[node->freq]= node;
            }
        } else{
           temp= freq[node->freq];

            node->next->prev= node->prev;
            node->prev->next= node->next;

            temp->next->prev= node;
            node->next= temp->next;
            node->prev= temp;
            temp->next= node;
            freq[node->freq]= node;
        } 
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node= mp[key];
        int res= node-> value;
        insert(node);
        // print();
        return res;
    }
    
    void put(int key, int value) {
        Node* node=NULL;
        if(mp.find(key) == mp.end()){
            //does not exist
            if(size == capacity){
                // cout<<size<<" "<<capacity<<" ";
                Node* temp= oldest->next;
                if(freq[temp->freq] == temp){
                    freq.erase(temp->freq);
                }
                mp.erase(oldest->next->key);
                // cout<<oldest->next->key;
                oldest->next= oldest->next->next;
                oldest->next->prev= oldest;
                size--;
            } 
            node= new Node(key, value); 
            size++;
            // temp->freq=1;
            mp[key]=node;
            oldest->next->prev= node;
            node->next= oldest->next;
            node->prev= oldest;
            oldest->next= node;
        }else{
            node= mp[key];
            node->value= value;
        }
        
        insert(node);
        // print();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */