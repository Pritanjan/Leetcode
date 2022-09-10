// https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    const int s = 100;
    vector<int> v[100] ;
    MyHashSet() {}
    
    void add(int key) {
        int i = key % s;
        if(!contains(key))
            v[i].push_back(key);
    }
    
    void remove(int key) {
        int i = key % s;
        for(int j=0; j<v[i].size(); j++)
            if(v[i][j] == key){
                v[i].erase(v[i].begin() + j);
                break;
            }
        
    }
    
    bool contains(int key) {
        int i = key % s;
        for(int j=0; j<v[i].size(); j++)
            if(v[i][j] == key)
                return true;
        
        return false;
    }
};


