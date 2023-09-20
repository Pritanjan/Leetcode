// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0006%20121122Maximum%20Sub-String%20after%20at%20most%20K%20changes.cpp

// A 1

class Solution {
public:
    int find(string &s, int k, int ch){
	    int max_len = 1;
	    int cnt = 0, L = 0, R = 0;
	    while(R < s.size()) {
	        if(s[R] != ch) cnt++;
	        while(cnt > k) {
	            if(s[L] != ch) cnt--;
                L++;
	        }
	        max_len = max(max_len, R - L + 1);
	        R++;
	    }
	    return max_len;
	}
	    
	int characterReplacement(string s, int k){
	    int max_len = 1;
		for(int i=0; i<26; i++){
		    max_len = max(max_len, find(s, k, i + 'A'));
		}
		return max_len;
	}
};






// A 2

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(26, 0); // Count of each uppercase English character
        int maxCount = 0; // Maximum character count in the current window
        int L = 0; // Left pointer of the window
        int maxLength = 0; // Length of the longest valid substring

        for(int R=0; R<s.length(); R++) {
            charCount[s[R] - 'A']++; // Increment count of the current character
            maxCount = max(maxCount, charCount[s[R] - 'A']); // Update maxCount

            // If the length of the current window minus maxCount exceeds k, shrink the window
            if(R - L + 1 - maxCount > k) {
                charCount[s[L] - 'A']--; // Decrement count of the character going out of the window
                L++; // Shrink the window from the left
            }

            // Update the maxLength for the current window
            maxLength = max(maxLength, R - L + 1);
        }
        return maxLength;
    }
};






// A 3

class Solution {
public:
    int characterReplacement(string s, int k) {
         int maxLen = 0; // Initialize the length of the longest valid substring
        int maxCnt = 0; // Initialize the maximum character count in any window
        int L = 0; // Initialize the left pointer of the window
        unordered_map<char, int> cnt; // Map to store the count of each character

        for(int R=0; R<s.length(); R++) {
            cnt[s[R]]++; // Increment the count of the current character
            maxCnt = max(maxCnt, cnt[s[R]]); // Update maxCount

            // Calculate the number of replacements needed to make all characters in the current window the same
            int tmp = (R - L + 1) - maxCnt;

            // If the number of replacements needed exceeds k, we need to shrink the window
            if(tmp > k) {
                cnt[s[L]]--; // Decrement the count of the character going out of the window
                L++; // Move the left pointer to the right, effectively shrinking the window
            }
            // Update maxLength for the current window
            maxLen = max(maxLen, R - L + 1);
        }    
        return maxLen; // Return the length of the longest substring with the same character
    }
};






// A 4

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int L = 0;
        unordered_map<char, int> cnt;
        priority_queue<int> pq;

        for(int R=0; R<s.length(); R++) {
            cnt[s[R]]++;
            pq.push(cnt[s[R]]);

            // Calculate the number of replacements needed
            int tmp = R - L + 1 - pq.top();

            // If the number of replacements needed exceeds k, shrink the window
            if(tmp > k) {
                cnt[s[L]]--;
                pq.pop();
                L++;
            }
            maxLen = max(maxLen, R - L + 1);
        }
        return maxLen;
    }
};






// A 5 - LEetcode A 1

class Solution {
public:
    bool canMakeValidSubstring(const string& s, int substringLength, int k) {
        vector<int> freqMap(26, 0);
        int maxFrequency = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            freqMap[s[end] - 'A']++;

            if (end + 1 - start > substringLength) {
                freqMap[s[start] - 'A']--;
                start++;
            }

            maxFrequency = max(maxFrequency, freqMap[s[end] - 'A']);

            if (substringLength - maxFrequency <= k) {
                return true;
            }
        }

        return false;
    }

    int characterReplacement(string s, int k) {
        int lo = 1;
        int hi = s.length() + 1;

        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            if (canMakeValidSubstring(s, mid, k)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;

    }
};

 



// A 6
