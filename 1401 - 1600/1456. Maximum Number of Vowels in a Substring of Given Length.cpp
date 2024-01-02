// A 0 - Brute Force  TLE

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0;
        for(int i=0; i<=s.length() - k; ++i) {
            int count = 0;
            for(int j=i; j<i+k; ++j) {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    count++;
                }
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};






// A 1 [ Sliding Window ]

// i use a sliding window approach to keep track of the number of vowels in a substring of length k
// while moving the window from left to right.
// We initialize variables vowels, maxVowels, left, and right to 0. 

// While the right pointer is within the bounds of the string, we check if the character at right 
// is a vowel. If it is, increment the vowels count. then check if the window size is equal to k.
// If it is, we update maxVowels to be the maximum of the current value of maxVowels and vowels.
// We then move the window by incrementing the left pointer and decrementing the vowels count
// if the character at left is a vowel. Finally, we increment the right pointer.

// Once the loop is complete, we return maxVowels, which represents the maximum number of vowels 
// in any substring of length k.

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int vowels = 0;
        int maxVowels = 0;
        int L = 0;
        int R = 0;

        while(R < s.size()) {
            if(isVowel(s[R])) vowels++;
            
            if(R - L + 1 == k) {
                maxVowels = max(maxVowels, vowels);
                if(isVowel(s[L])) vowels--; 
                L++;
            }
            R++;
        }
        return maxVowels;
    }
};






// A 2 [ Sliding Window usisng set ]

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        // Build the window of size k, count the number of vowels it contains.
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += vowels.count(s[i]);
        } 
        
        int answer = count;
        // Slide the window to the right, focus on the added character and the
        // removed character and update "count". Record the largest "count".
        for (int i = k; i < s.length(); i++) {
            count += vowels.count(s[i]) - vowels.count(s[i - k]);
            answer = max(answer, count);
        }
        return answer;
    }
};


// OR


class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int maxCount = 0;
        int count = 0;
        for(int i=0; i<k; ++i) {
            if(isVowel(s[i])) count++;
        }

        maxCount = count;
        for(int i=k; i<s.length(); ++i) {
            if(isVowel(s[i - k])) count--;
            if(isVowel(s[i])) count++;
            
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};






// A 3 [ Prefix Sum ] 

class Solution {
public:        
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> prefixSum(n + 1, 0);
        
        for(int i=1; i<=n; i++) {
            prefixSum[i] = prefixSum[i - 1] + isVowel(s[i - 1]);
        }

        int maxCount = 0;
        for(int i=k; i<=n; i++) {
            maxCount = max(maxCount, prefixSum[i] - prefixSum[i - k]);
        }
        return maxCount;
    }
};






// A 4 

