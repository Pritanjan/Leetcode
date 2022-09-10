//https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    string sortString(int n){
        // since the input is an integer,
        // we convert it to a string first
        string s = to_string(n);
        // sort the string
        sort(s.begin(), s.end());
        // return the string
        return s;
    }
    
    // the idea is to sort `n` and compare all sorted power of two
    // if they are matched, then it means they can be reordered to each other
    bool reorderedPowerOf2(int n) {
        // since the sorted string of n is always same
        // so we convert it here instead of doing it in the loop
        string s = sortString(n);
        for (int i = 0; i < 30; i++) {
            // power of 2 = 1 << i
            // we sort each power of 2 string
            string t = sortString(1 << i);
            // and compare with `s`
            // if they are matched, then return true
            if (s == t) return true;
        }
        // otherwise it is not possible to reorder to a power of 2
        return false;
    }
};
