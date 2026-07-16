//     head <-> ... <-> tail
//     * head->next  = LRU
//     * tail->prev  = MRU
// - mp maps key -> Node*
// - get(key):
//     * if key not in mp: return -1
//     * else: move node to MRU position (before tail) and return value
// - put(key, value):
//     * if key exists: update value and move node to MRU
//     * else:
//         - if at capacity: remove LRU node (head->next) and erase from mp
//         - insert new node as MRU (before tail) and store in mp

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;        
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        remove(mp[key]);
        add(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            add(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = head->next;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);
        }
    }
};
