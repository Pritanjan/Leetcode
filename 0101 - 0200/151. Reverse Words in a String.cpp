// GFG
// https://www.geeksforgeeks.org/reverse-words-in-a-given-string/

// APPROACH 1

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        
        while(ss >> word)  ans = word + " " + ans;
        ans.pop_back();
        return ans;
    }
};





// APPROACH 2 

// THIS CODE DOESENT REMOVE SPACES IN B/W THEM 

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        
        // Reverse each word in the sentence
        for(int end = 0; end < n; end++){
            if(s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        // Reverse the last word
        reverse(s.begin() + start, s.end());
        
        // Reverse the whole sentence
        reverse(s.begin(), s.end());
        
        return s;
    }
};




// CORRECT CODE 
// Reverse words in a given string using the swap operation: FROM GFG


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        bool space = true;   // flag to check if there is space between words
        
        // Reverse each word in the sentence
        for(int end=0; end<n; end++) {
            if(s[end] == ' '){
                // if there is no space between words, reverse the previous word
                if(!space) reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
                space = true;
            }
            else space = false;
        }

        // Reverse the last word
        reverse(s.begin() + start, s.end());
        
        // Reverse the whole sentence
        reverse(s.begin(), s.end());
        
        // Remove unnecessary spaces
        int i = 0;
        while(s[i] == ' ') i++; // remove leading spaces
            
        int j = s.size() - 1;
        while(s[j] == ' ') j--; // remove trailing spaces
            
        string reversed = "";
        bool add_space = false;
        for(int k=i; k<=j; k++){
            if(s[k] == ' ') add_space = true;
            else {
                if(add_space){
                    reversed += ' ';
                    add_space = false;
                }
                reversed += s[k];
            }
        }
        return reversed;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)


// LAST FROM GFG
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == ' '){
                if(temp != "") ans = temp + " " + ans;
                temp = "";
            }
            else temp += ch;
        }

        if(temp != "") ans = temp + " " + ans;
        return ans.substr(0, ans.length()-1);
    }
};


// T.C. --> O(N)
// S.C. --> O(1)



