//All the elements in the array have been initialised to false ( to show that element does not exist)
//
//All the elements that can be added to the array are already present in the array in the form of index.
//
//If we add an element , we change the arr[element] = true ( to show that element does exist)
//Similarly we can remove the element.
//
//hashset.contains() directly returns the element in the position of the index.

// https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    vector<bool> design;
    
    MyHashSet() 
    // : design(1e6 + 1, false) 
    {
        design = vector <bool> (1e6 + 1, false);
    }
    
    void add(int key) {
        design[key] = true;
    }
    
    void remove(int key) {
        design[key] = false;
    }
    
    bool contains(int key) {
        return design[key] == true;
    }
};

// Complexity

// Time: O(1)
// Space: O(n)
