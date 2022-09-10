// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int a = 0;
        for(int i = 0; i <= s.length(); ++i){
            if(s[i] == ' '){
                reverse(&s[a], &s[i]);
                a = i + 1;
            }
        }
        reverse(s.begin()+a, s.end());
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        size_t a = 0;
        for(int i = 0; i <= s.length(); ++i){
            if(i == s.length() || s[i] == ' '){
                reverse(&s[a], &s[i]);
                a = i + 1;
            }
        }        
        return s;
    }
};

//what is the function of '&' at reverse()?
//Its to pass the value as address so that the code does not 
//take extra time to make a copy and makes changes in it.
//Here the changes are directly reflected on the original string

// why use size_t?
// It is a variable to assign size
// Since we are using reference in reverse function
// So we declare front as size_t




