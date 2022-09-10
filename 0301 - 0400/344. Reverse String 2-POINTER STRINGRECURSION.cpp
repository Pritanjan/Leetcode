// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            s.push_back(s[i]);
        }
        s.erase(s.begin(), s.begin() + n);
        return ;
        
    }
};

