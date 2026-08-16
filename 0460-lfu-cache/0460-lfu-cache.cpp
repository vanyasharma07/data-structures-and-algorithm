class LFUCache {
private:

    struct Node {
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    int minFreq;

    // key -> Node
    unordered_map<int, Node*> keyMap;

    // frequency -> DLL of nodes having that frequency
    unordered_map<int, list<Node*>> freqMap;

    // key -> iterator pointing to its position in freqMap[freq]
    unordered_map<int, list<Node*>::iterator> pos;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {

        int oldFreq = node->freq;

        // Remove node from old frequency list
        freqMap[oldFreq].erase(pos[node->key]);

        // If this was the minimum frequency
        // and no nodes remain at this frequency
        if (oldFreq == minFreq && freqMap[oldFreq].empty()) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Add node to new frequency list
        freqMap[node->freq].push_front(node);

        // Store its new position
        pos[node->key] = freqMap[node->freq].begin();
    }

    int get(int key) {

        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];

        // Accessing the node increases its frequency
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            node->value = value;

            // Updating an existing key counts as usage
            updateFreq(node);

            return;
        }

        // Cache is full
        if (keyMap.size() == capacity) {

            // Get least frequently used frequency
            int freq = minFreq;

            // Within that frequency,
            // remove the least recently used node
            Node* lru = freqMap[freq].back();

            int removeKey = lru->key;

            freqMap[freq].pop_back();

            keyMap.erase(removeKey);
            pos.erase(removeKey);

            delete lru;
        }

        // Create new node
        Node* node = new Node(key, value);

        keyMap[key] = node;

        // New nodes always have frequency 1
        minFreq = 1;

        freqMap[1].push_front(node);

        pos[key] = freqMap[1].begin();
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */