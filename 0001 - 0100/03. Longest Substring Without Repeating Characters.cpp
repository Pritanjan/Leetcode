// APPROACH 1 [ Brute force with hash set ]

// Here, we are considering all possible substrings and check whether they have repeating characters.
// We will be using a hash set to keep track of the characters in each substring and 
// check if a character is already in the hash set before adding it. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            unordered_set<char> seen;
            int j = i;
            while(j < n && !seen.count(s[j])) {
                seen.insert(s[j]);
                j++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};

// T.C. --> O(N^3),  N is the length of the input string
// Since we need to consider all n(n+1)/2 substrings of the input string,






// APPROACH 2 [  Sliding window with hash set ]

// Using a sliding window approach to solve the problem more efficiently than brute force.
// We can maintain a hash set to keep track of the characters in the current substring, 
// and use two pointers, i and j, to define the current substring.
// We can move the end pointer to the right and add the new character to the hash set. 
// If the new character is already in the hash set, we move the start pointer to the right
// until the repeating character is removed from the hash set. We can update the maximum
// length of the substring seen so far at each step.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> seen;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (!seen.count(s[j])) {
                seen.insert(s[j++]);
                ans = max(ans, j-i);
            } 
            else seen.erase(s[i++]);
        }
        return ans;
    }
};

// T.C. --> O(N),  N is the length of the input string
// Since each character is visited at most twice once with the end pointer and once with start pointer.

// S.C. --> O(min(n, m)) where m is the size of the character set. 
// We need to store the characters in the hash set, which can take up to m space in the worst case.

    
    


// APPROACH 3 [  Sliding window with hash map ]

// We can further optimize the sliding window approach by using a hash map to keep track 
// of the last occurrence of each character in the input string. 
// Instead of moving the start pointer one character at a time until the repeating character
// is removed from the hash set, 
// we can directly move the start pointer to the next position after the last occurrence
// of the repeating character.
// We can update the maximum length of the substring seen so far at each step.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> last_seen;
        int ans = 0, i = 0;
        for (int j = 0; j < n; j++) {
            if (last_seen.count(s[j])) {
                i = max(i, last_seen[s[j]]+1);
            }
            ans = max(ans, j-i+1);
            last_seen[s[j]] = j;
        }
        return ans;
    }
};


// T.C. --> O(n) where n is the length of the input string.
// We visit each character at most twice, once with the j pointer and once with the i pointer.

// S.C. --> O(min(n, m)) where m is the size of the character set. 
// We need to store the last occurrence of each character in the hash map, 
// which can take up to m space in the worst case.
    





// APPROACH 4

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int start = -1;
        int lensub = 0;
        for(int i=0; i<s.size(); i++){
            if(v[s[i]] > start)  start  = v[s[i]];
            v[s[i]] = i;
            
            lensub = max(lensub, i-start);
        }
        return lensub;
    }
};

// T.C. --> O(N),  N is the length of the input string





// APPROACH 5 [ SLIDING WINDOW ]

// Here the L and R pointers define the substring, and a vector called v is used to keep track 
// of the occurrence of each character in the substring.

// The code iterates over the string s until the right pointer R reaches the end of the string.
// In each iteration, it increments the count of the character at the right pointer in the v vector. 
// If the occurrence count becomes more than 1, it contracts the present window by moving the
// left pointer L and decrementing the occurrence count of the character at the left pointer.

// At the end of each iteration, the code updates the lensub variable with the maximum length 
// of the substring found so far. The final value of lensub is returned as the result.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256);      // array to store the occurence of all the charracter
        int L = 0;
        int R = 0;
        int lensub = 0;          // initializing the required length as 0
        while(R < s.length()){   // iterate over the string till the right pointer reaches the end of the string 
            v[s[R]]++;           // increment the count of the character present in the right pointer 
            
            while(v[s[R]] > 1){  // if the occurence become more than 1 means the char is repeated
                v[s[L]]--;       // if the occurence become more than 1 means the char is repeated
                L++;             // contraction of the present window till the occurence of the 't' char becomes 1
            }            
            lensub = max(lensub, R-L+1);    // As the index starts from 0 , lensub will be (right pointer-left pointer + 1)
            R++;                   // now will increment the right pointer 
        }
        return lensub;
    }
};


// T.C. --> O(N), N is the length of the input string
// Since each character is visited at most twice.

// S.C. --> O(1),  
// Since the size of the v vector is constant at 256.

