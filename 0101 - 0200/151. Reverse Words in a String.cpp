// https://leetcode.com/problems/reverse-words-in-a-string/
// https://www.geeksforgeeks.org/stringstream-c-applications/


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        
        while(ss >> word){
            ans = word + " " + ans;
        }
        ans.pop_back();
        
        return ans;
    }
};


