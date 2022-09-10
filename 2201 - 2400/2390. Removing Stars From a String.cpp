//https://leetcode.com/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '*')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};

// Use a stack to store the characters.
// Pop one character off the stack at each star. 
// Otherwise, we push the character onto the stack.
