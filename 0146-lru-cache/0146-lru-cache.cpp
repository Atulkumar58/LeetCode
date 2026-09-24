class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int a, int b){
        key=a, value= b;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> m;
    Node* oldest;
    Node* newest;
    int size, capacity;
    LRUCache(int capacity) {
        size=0;
        this->capacity= capacity;
        oldest= new Node(0, 0);
        newest= new Node(0, 0);
        oldest->next= newest;
        newest->prev= oldest;
        this->capacity=capacity;
    }
    void insert(Node* node){
        newest->prev->next= node;
        node->prev= newest->prev;

        newest->prev= node;
        node->next= newest;
    }
    void remove(Node* node){
        node->prev->next= node->next;
        node->next->prev= node->prev;
    }
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* node= m[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        Node* temp= new Node(key, value);
        
        if(m.find(key) != m.end()){
            m[key]->value= value;
            remove(m[key]);
            insert(m[key]);
            return;
        }
        m[key]= temp;
        insert(temp);
        size++;

        if(size > capacity){
            m.erase(oldest->next->key);
            remove(oldest->next);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */