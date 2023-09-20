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
