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
