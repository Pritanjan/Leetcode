// https://leetcode.com/problems/reverse-words-in-a-string-iii/solutions/2052689/c-2-solution-2-pointer-stl-with-explanation/

// APPROACH 1

class Solution {
public:
    string reverseWords(string s) {
        int j = -1;
        int n = s.size();
        for(int i=0; i<=n; i++){
            if(i == n or s[i] == ' '){
                int L = j + 1;
                int R = i - 1;
                
                while(L < R){
                    char ch = s[L];
                    s[L] = s[R];
                    s[R] = ch;
                    L++;
                    R--;
                }
                j = i;
            }
        }
        return s;
    }
};





// APPROACH 2

class Solution {
public:
    string reverseWords(string s)  {
        stringstream ss(s);
        string ans;
        string word;
        
        while(ss >> word) {
            reverse(word.begin(), word.end());   //reversing and adding
            ans += word + ' ';
        }
        ans.pop_back();    //for the last extra space
        return ans;
    }
};





// APPROACH 3

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        istringstream str(s);
        for(string s; str>>s; ){
            int first = 0, last = s.size()-1;
            while(first < last) swap(s[first++], s[last--]);
            ans += ans == "" ? s : " " + s;
        }
        return ans;
    }
};






// APPROACH 4

// It uses 2 pointers a and i to iterate through each word in the string.
// Whenever a space character is encountered, the characters in the current 
// word are reversed using the reverse function from the algorithm library. 
// Finally, the order of the last word is reversed after the loop end

class Solution {
public:
    string reverseWords(string s) {
        int a = 0;
        for(int i=0; i<=s.length(); ++i){
            if(s[i] == ' '){
                // reverse(s.begin() + a, s.begin() + i);
                reverse(&s[a], &s[i]);
                a = i + 1;
            }
        }
        reverse(s.begin()+a, s.end());
        return s;
    }
};





// OR 


class Solution {
public:
    string reverseWords(string s) {
        size_t a = 0;
        for(int i=0; i<=s.length(); ++i){
            if(i == s.length() || s[i] == ' '){
                reverse(&s[a], &s[i]);
                a = i + 1;
            }
        }        
        return s;
    }
};

// function of '&' at reverse()?
// Its to pass the value as address so that the code does not 
// take extra time to make a copy and makes changes in it.
// Here the changes are directly reflected on the original string

// why use size_t?
// It is a variable to assign size
// Since we are using reference in reverse function
// So we declare front as size_t







// APPROACH 5


class Solution {
public:
    string reverseWords(string s) {
        string result;
        int lastSpace = -1;
        for(int i = 0; i < s.length(); i++) {           // i --> strIndex
            if((i == s.length() - 1) || s[i] == ' ') {
                int revEnd = (i == s.length() - 1) ? i : i - 1;
                for (; revEnd > lastSpace; revEnd--) result += s[revEnd];
                if (i != s.length() - 1) result += ' ';
                lastSpace = i;
            }
        }
        return result;
    }
};

