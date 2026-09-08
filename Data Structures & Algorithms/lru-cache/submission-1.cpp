class LRUCache {
   public:
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = this;
            next = this;
        }
    };

    unordered_map<int, Node*> mp;
    Node* t;
    int cap;

    // Insert node immediately after t = MRU position
    void insert(Node* nn) {
        nn->next = t->next;
        nn->prev = t;

        t->next->prev = nn;
        t->next = nn;
    }

    // Remove a node from the circular list
    void remove(Node* v) {
        v->prev->next = v->next;
        v->next->prev = v->prev;
    }

    LRUCache(int capacity) {
        cap = capacity;

        t = new Node(0, 0);

        // Circular sentinel
        t->next = t;
        t->prev = t;
    }

    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* v = mp[key];

        // This key was just used, so make it MRU
        remove(v);
        insert(v);

        return v->val;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* v = mp[key];

            v->val = value;

            // Move it to MRU
            remove(v);
            insert(v);

            return;
        }

        // New key
        Node* nn = new Node(key, value);

        insert(nn);
        mp[key] = nn;

        // Capacity exceeded
        if (mp.size() > cap) {
            Node* lru = t->prev;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};