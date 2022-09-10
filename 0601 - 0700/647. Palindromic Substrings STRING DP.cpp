//https://leetcode.com/problems/palindromic-substrings/

//terate the word, for each character, judge palindromic substrings by applying a fucntion palindrom. There are two cases, the
//palindromic string length is odd or even. For example aaa, aa. The fucntion palindrom checks from the center to end. If the two
//character equals, move on, left pointer moves left, right pointer moves right, if not, break the loop.

class Solution {
public:
    void PalindromicSubstrings(string s, int left, int right, int& cnt) {  //judge if a substring is palindromic
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int i = 0;
        while(n--){
            PalindromicSubstrings(s,i,i,count);  //judge odd substring

            PalindromicSubstrings(s,i,i+1,count); //judge even substring

            i++;
        }
        return count;
    }
};
