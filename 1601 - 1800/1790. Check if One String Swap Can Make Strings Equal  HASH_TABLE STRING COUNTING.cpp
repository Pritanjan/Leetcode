// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i])
                diff.push_back(i);
                // diff.emplace_back(i);  // both line are same
            
            if(diff.size() > 2)
                return false;
        }
        
        if(diff.empty())
            return true;
        
        if(diff.size() == 2)
            swap(s1[diff[0]], s1[diff[1]]);  
        // Once we have found 2 positions where the chars in both the strings differ, we attempt a swap operation to check if both the strings become equal.
		// swap(s1[diff_pos[0]], s1[diff_pos[1]]) -> This is swapping the chars in string s1 at positions diff_pos[0] & diff_pos[1].


        return s1 == s2;
    }
};
