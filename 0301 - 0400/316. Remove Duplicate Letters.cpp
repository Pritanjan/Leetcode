// A 1

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> count(128);
        vector<bool> used(128);

        // Count the frequency of each character in the string
        for(const char c : s) ++count[c];

        // Iterate over the string and remove duplicate characters
        for(const char c : s) {
            --count[c];            
            if(used[c]) continue;
            while (!ans.empty() && ans.back() > c && count[ans.back()] > 0) {
                used[ans.back()] = false;
                ans.pop_back();
            }
            used[c] = true;
            ans.push_back(c);
        }
        return ans;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)

 // It uses two vectors, "count" and "used", to keep track of the frequency of characters in the string
// and whether a character has already been used, respectively. 
// The function iterates over the string and removes duplicate characters while maintaining the original
// order of the characters in the string. 
// It initializes an empty string called "ans" and two vectors "count" and "used", each of size 128. 
// It then counts the frequency of each character in the input string using a for-each loop, 
// and updates the "count" vector accordingly.

// It iterates over each character in the input string and does the following for each character:
// -> Decrement the frequency of the current character in the "count" vector.
// -> If the current character has already been used, continue to the next character.
// -> While the "ans" string is not empty and the last character in the "ans" string is greater than
//    the current character, and the frequency of the last character in the "count" vector is greater
//    than 0, remove the last character from the "ans" string and mark it as unused in the "used" vector.
// -> Mark the current character as used in the "used" vector and append it to the "ans" string.
// Finally, the function returns the resulting string with duplicate characters removed.






// A 2 SAME AS 1 (USING STACK)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> cnt(26, 0);
        vector<bool> vis(26, false);
        for(char c : s) cnt[c - 'a']++;
    
        for(char c : s) {
            cnt[c - 'a']--;
            if(vis[c - 'a']) continue ;        
            while(!st.empty() && c < st.top() && cnt[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            vis[c - 'a'] = true;
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};






// A 3
// Here we are using 2 integer arrays to keep track of the count & max index of each character
// in the string, and nested loop to find the lexicographically smallest character at each iteration.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0), maxs(26, -1);
        string result = "";

        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            maxs[s[i] - 'a'] = i;
        }
        
        int start = 0;
        while(start < s.size()) {
            int min = 26;
            int idx = -1;
            for(int i = start; i < s.size(); i++) {
                if(count[s[i] - 'a'] == 0) continue;
                if(s[i] - 'a' < min) {
                    min = s[i] - 'a';
                    idx = i;
                }
                if(count[s[i] - 'a'] == 1 || maxs[s[i] - 'a'] <= i) break;
            }
            
            if(idx == -1) break;
            for(int i = start; i < idx; i++) {
                count[s[i] - 'a'] = max(0, count[s[i] - 'a'] - 1);
            }
            count[min] = 0;
            result += (char)(min + 'a');
            start = idx + 1;
        }
        return result;
    }
}; 

// T.C. --> O(N)
// S.C. --> O(1)


// OR


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c - 'a']++;
        
        int pos = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[pos] > s[i]) pos = i;
            if(--cnt[s[i] - 'a'] == 0) break;
        }
        
        if(s.empty()) return "";
        string rem = s.substr(pos + 1);
        char tmp = s[pos];
        rem.erase(remove(rem.begin(), rem.end(), tmp), rem.end());
        return tmp + removeDuplicateLetters(rem);
    }
};





// A 4


