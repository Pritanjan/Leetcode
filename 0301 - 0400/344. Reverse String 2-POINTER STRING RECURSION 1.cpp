// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        
        int left  =  0;
        int right = s.size() - 1;
        
        while(left <= right){
            swap(s[left], s[right]);
                left++; right--;
        }
        
    }
};

// Here we’re using the Two Pointer Approach.
//
// We’ll use the swap function which takes O(1) time complexity.
//
// Take 2 pointers to start & end, swap them and move the pointer.
//
// Time complexity: O(n).



