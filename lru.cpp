 
 //LRU,双链表
 
 struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* end; 

    // 删除节点
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 插入到头部
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        end = new Node(0, 0);
        head->next = end;
        end->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = end->prev;
                cache.erase(lru->key);
                remove(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            insert(node);
        }
    }
};  