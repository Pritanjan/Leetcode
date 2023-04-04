// APPROACH 1 [ SLIDING WINDOW APPROACH ]


// It iterate over all possible substrings of s, and checks each substring to see whether it is 
// balanced or not. 

// 1. Initialize variables: 
//    ans to 0 (which will hold the length of the longest balanced substring found so far), 
//    pre to 0 (which will hold the length of the previous substring), 
//    cur to 0 (which will hold the length of the current substring), 
//    and n to the length of the input string s.
// 2. Loop over all characters in s, incrementing cur by 1 for each character.
// 3. If the current character is not the same as the next character or if the loop has reached
//    the end of the input string (i == s.length() - 1), it means that the current substring has ended.
// 4. Check whether the current substring is balanced by comparing the length of the previous 
//    substring (pre) and the current substring (cur), and multiplying the smaller length by 2 
//    (since a balanced substring must have an equal number of '0's and '1's).
// 5. Update ans to be the maximum of the current ans and the length of the balanced substring 
//    found in step 4.
// 6. Update pre to be equal to cur, and reset cur to 0 to start a new substring.
// 7. Return ans as the final result.



class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, pre = 0, cur = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cur;
            if (i == s.length() - 1 || s[i] != s[i + 1]) {
                if (s[i] == '1')
                    ans = max(ans, min(pre, cur) * 2);
                pre = cur;
                cur = 0;
            }
        }
        return ans;
    }
};


// T.C. --> O(N), where n is the length of the input string s, 
// since each character in s is visited only once.

// S.C. --> O(1)







// APPROACH 2


class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0;
        for(int i=0; i<s.size()-1; i++) {
            if(s[i] == '0') {
                int zero = 1, one = 0;
                bool flag = false;
                for(int j=i+1; j<s.size(); j++) {
                    if(one > zero) {
                            int length = min(zero, one);
                            res = max(res, 2*length);
                            break;
                    }
                    if(s[j] == '1') {
                        flag = true;
                        one++;
                    }
                    if(s[j] == '0') {
                        if(flag) {
                            int length = min(zero, one);
                            res = max(res, 2*length);
                            break;
                        }
                        else zero++;
                    }
                }
              
                int length = min(zero, one);
                res = max(res, 2*length);
            }
        }
        return res;
    }
};





// APPROACH 3

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i, zeroes = 0, ones = 0;
            while (j < n && s[j] == '0') {
                zeroes++;
                j++;
            }
            int k = j;
            while (k < n) {
                if (s[k] == '1') ones++;
                if (s[k] == '0') break;
                if (ones == zeroes) {
                    res = max(res, k - i + 1);
                }
                k++;
            }
        }
        return res;
    }
};



