// A 1

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


// OR


class Solution {
public:
    string reverseWords(string s) {
        // Split the input string into words
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word)  words.push_back(word);

        // Reverse the vector of words
        reverse(words.begin(), words.end());

        // Join the words into a string with spaces
        string reversed = "";
        for(int i=0; i<words.size(); i++) {
            if(i > 0) reversed += " ";
            reversed += words[i];
        }        
        return reversed;
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
        
        // Remove extra spaces
        int i = 0, j = 0;
        while(j < n) {
            while (j < n && s[j] == ' ') j++;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        s.resize(i);
        return s;
    }
};






// A 3
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





// A 4 - LAST FROM GFG

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


// OR
// Using reverse iteration


class Solution {
public:
    string reverseWords(string s) {    
        string res;
        int end = s.size();
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ' ') end = i;
            else if(i == 0 || s[i-1] == ' ') {
                if(!res.empty()) res += ' ';
                res += s.substr(i, end - i);
            }
        }
        return res;
    }
};





// A 5

class Solution {
public:
    //Flip, interval writing: left closed right closed []
    void reverse(string& s, int start, int end){  
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    //Remove all spaces and add spaces between adjacent words, fast and slow pointers.
    void removeExtraSpaces(string& s) { 
        int slow = 0;  
        for (int i = 0; i < s.size(); ++i) { //
            //Process when non-space is encountered, that is, delete all spaces.
            if (s[i] != ' ') { 
                // manually controls whitespace, adding spaces between words. slow != 0 indicates that it is not the first word, and a space needs to be added before the word.
                if (slow != 0) s[slow++] = ' '; 
                
                //Fill the word, if a space is encountered, it means the end of the word.
                while (i < s.size() && s[i] != ' ') { 
                    s[slow++] = s[i++];
                }
            }
        }
        //The size of slow is the size after removing extra spaces.
        s.resize(slow); 
    }

    string reverseWords(string s) {
        //Remove redundant spaces, ensure that there is only one space between words, and there are no spaces at the beginning and end of the string
        removeExtraSpaces(s); 
        reverse(s, 0, s.size() - 1);
        
        // After removeExtraSpaces, ensure that the start subscript of the first word must be 0.
        int start = 0; 
        for (int i = 0; i <= s.size(); ++i) {
            // Reaching a space or the end of a string indicates the end of a word. to flip.
            if (i == s.size() || s[i] == ' ') { 
                //Flip, pay attention to the flip of left-closed-right-closed [].
                reverse(s, start, i - 1); 
                
                // Update the start subscript start of the next word 
                start = i + 1; 
            }
        }
        return s;
    }
};





// A 6 - Using two-pointer 

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        
        // Remove leading spaces
        while(i < n && s[i] == ' ') i++;
                
        string res = "";
        while(i < n) {
            int j = i;
            while(j < n && s[j] != ' ') j++;
            string word = s.substr(i, j - i);
            
            if(res.empty()) res = word;
            else res = word + " " + res;
                        
            while(j < n && s[j] == ' ') j++;
            
            i = j;
        }        
        s = res;
        return res;
    }
};





// A 7 - Using Stack

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        istringstream iss(s);
        string word;
        
        while(iss >> word) {
            stk.push(word);
        }
        
        string reversed;
        while(!stk.empty()) {
            reversed += stk.top();
            stk.pop();            
            if(!stk.empty()) reversed += " ";
        }        
        return reversed;        
    }
};





// A 8

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading spaces
        int i = 0;
        while(i < s.length() && s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        
        // reversing words       
        // Reverse the entire string
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        int n = s.length();

        while(start < n) {
            // Find the start and end of a word
            while(start < n && s[start] == ' ') start++;
            end = start;
            while(end < n && s[end] != ' ') end++;
            
            // Reverse the word
            reverse(s.begin() + start, s.begin() + end);
            start = end;
        }

        // Remove extra spaces
        i = 0;
        int j = 0;
        while(j < n) {
            while(j < n && s[j] == ' ') j++;
            while(j < n && s[j] != ' ') s[i++] = s[j++];
            if(j < n) s[i++] = ' ';
        }

        s.erase(s.begin() + i, s.end());
        return s;
    }
};





// A 9
