// A 1
// 1. Traverse the string and find every word's start and end index. And then, we will reverse each word.
// 2. Find the first index and last index of every word by L and R.
// 3. Swap the characters in the word pointed byL and R.
// 4. Increment L by 1 and decrement R by 1.
// 5. Repeat steps 3 and 4 until L < R.

// IT same as A 4

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

// Time Complexity : - O(N)
// Space Complexity :- O(1)


// OR


class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.length();
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};







// A 2
// It uses a stringstream object to read each word from the input string s. 
// Then, it reverses each word using the reverse function and
// appends it to the result stringwith a space.
// Finally, the last space character is removed from the result string using the pop_back function.

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

// T.C. --> O(nwlog(w)), where n & w is the length of the input string & maximum word length. 
// Because for each word, we need to reverse the characters in that word, 
// which takes O(w * log(w)) time using the reverse function.
// S.C. --> O(n), where n is the length of the input string. 
// Because we need to store the reversed words in a result string, which can be at most 
// as long as the input string if all words have length 1.

// Note that the stringstream object may also use additional space proportional to the length
// of the input string, but this is not included in the space complexity analysis
// since it is temporary and gets deallocated after the function call.


// OR


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






// A 5

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






// A 6

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for(char c : s) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            } else word += c;
        }

        words.push_back(word);
        for(string& word : words) reverse(word.begin(), word.end());
        
        return accumulate(words.begin(), words.end(), string(), [](string& result, string& word) {
            if (result.empty()) return word;
            else return result + " " + word;
        });
    }
};

// T.C. --> O(n * m), where n & m is the length of string s and maximum length of a word 

// The for loop in the first pass iterates over each character of the string s,
// so it has a time complexity of O(n).

// The second pass iterates over each word in the vector of words, and for each word, it reverses
// the order of its characters. The T.C. complexity of reversing a string of length m is O(m/2), 
// so the overall time complexity of this pass is O(m*n).

// The accumulate function concatenates all the reversed words with spaces in between, 
// so it has a time complexity of O(n).


// S.C. -->  O(n + m), where n & m is the length of string s and total length of all the words in s.

// The vector of words stores each word in s as a separate string, so its space complexity is O(m).
// The reversed version of each word is stored in place within the vector, so no extra space is 
// needed for that.
// The accumulate function concatenates all the reversed words with spaces in between, so the
// space complexity of the resulting string is O(n + m).



// A 7

class Solution {
public:
    void reverse(string& s, int first, int last) {
        while(first < last) {
            swap(s[first], s[last]);
            first++;
            last--;
        }
    }

    string reverseWords(string s) {
        int slow = 0, fast = 0, s_length = s.length();
        while(1) {
            if((s[fast + 1] == ' ' || s[fast + 1] == '\0') && s[fast] != ' ') {
                reverse(s, slow, fast);
                if (fast + 1 == s_length) return s;
                slow = fast + 2;
            }
            fast++;
        }
    }
};


// T.C. --> O(n), where n is the length of the input string. 
// Because it iterates through the string once to reverse each word, and since each character
// in the string is visited exactly once, the time complexity is linear.

// S.C. --> O(1) 
// because it only uses a constant amount of extra space, namely a few integer variables and 
// a temporary variable in the reverse function. The reverseWords function operates directly 
// on the input string, without creating any additional strings or arrays, 









