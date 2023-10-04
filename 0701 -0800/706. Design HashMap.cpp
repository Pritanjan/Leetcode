// A 1 

class MyHashMap {
public:    
    vector<int> v;
    int size;
    MyHashMap() {
        v.resize(1e6+1, -1);
        // size = 1e6 + 1;
        // v.resize(size);
        // fill(v.begin(), v.end(), -1);
    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};






// A 2

class MyHashMap {
private:
    vector<vector<pair<int, int>>> vp;
    const int capacity = 10000; // Choose a suitable capacity

    // Hash function to map keys to indices in the data vector
    int hash(int key) {
        return key % capacity;
    }

public:
    // Initialize your data structure here.
    MyHashMap() {
        vp.resize(capacity);
    }

    // Insert a (key, value) pair into the HashMap.
    // If the key already exists, update the corresponding value.
    void put(int key, int value) {
        int idx = hash(key);
        for(auto &pair : vp[idx]) {
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        }
        vp[idx].push_back({key, value});
    }

    // Get the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    int get(int key) {
        int idx = hash(key);
        for (const auto &pair : vp[idx]) {
            if(pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    // Remove the mapping for a key if it exists.
    void remove(int key) {
        int idx = hash(key);
        auto &bucket = vp[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if(it -> first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};






// A 3








