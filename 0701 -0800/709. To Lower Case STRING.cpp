// APPROACH 1

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch : s) {
            ch = tolower(ch);
        }
        return s;
    }
};


// OR

class Solution {
public:
    string toLowerCase(string s) {
        string res = s;
        for(size_t i=0; i<res.size(); ++i) {
            if(isupper(res[i])) res[i] = tolower(res[i]);
        }
        return res;
    }
};


// OR

class Solution {
public:
    string toLowerCase(string s) {
        string res = s;
        transform(res.begin(), res.end(), res.begin(), [](char c) {
            return tolower(c);
        });
        return res;
    }
};






// APPROACH 2 [  Index Manipulation ]

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch : s) {
            if(ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
        }
        return s;
    }
};



