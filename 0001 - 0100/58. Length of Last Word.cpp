// APPROACH 1 [ Splitting the String ]
// Split the input string into words using space as a delimiter.
// Find the last non-empty word after splitting and return its length.

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word;
        while (iss >> word) {}
        return word.size();
    }
};





// APPROACH 2

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != ' ') size++;
            // and size > 0  is added because if space is given 
            // in the last 
            // s = "   fly me   to   the moon  "
            if(s[i] == ' ' and size > 0) return size;
        }
        return size;
    }
};




// A3 [ 2 POINTER ]

class Solution {
public:
    int lengthOfLastWord(string s) {
        int R = s.length() - 1;
        while(R >= 0 && s[R] == ' ') R--;
        int L = R;
        while(L >= 0 && s[L] != ' ') L--;
        return R - L;
    }
};






// A 4 - STL

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto it = find_if(s.rbegin(), s.rend(), ::isalpha);
        auto it_end = find_if_not(it, s.rend(), ::isalpha);
        return distance(it, it_end);
    }
};


// OR


class Solution {
public:
    int lengthOfLastWord(string s) {
        auto lastSpace = find_if(s.rbegin(), s.rend(), [](char c) { return c != ' '; });
        auto firstSpace = find_if(lastSpace, s.rend(), [](char c) { return c == ' '; });
        return distance(lastSpace, firstSpace);
    }
};






// A 5 

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool found = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                found = true;
                length++;
            } else if (found) {
                break;
            }
        }
        return length;
    }
};

