//https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch : s){
            ch = tolower(ch);
        }
        return s;
    }
};


// APPROACH 2

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch : s){
            // ch = tolower(ch);
            if(ch >= 'A' && ch <= 'Z')
                ch += 'a' - 'A';
        }
        return s;
    }
};
