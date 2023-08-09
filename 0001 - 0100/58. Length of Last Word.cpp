// APPROACH 1 [ Splitting the String ]

// Split the input string into words using space as a delimiter.
// Find the last non-empty word after splitting and return its length.

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream s1(s);
        string s2;
        while(s1 >> s2){}
        return s2.size();
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



