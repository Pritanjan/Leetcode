// A 1 

class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        // for(char i : s){
        for(char i='A'; i<='z'; i++){
            odd += count(s.begin(), s.end(), i) & 1;
        }    
        return s.size() - odd + (odd > 0);
    }
};






// A 2 -  Greedy (Hash Table)

class Solution {
public:
    int longestPalindrome(string s) {
        // Map to store frequency of occurrence of each character
        unordered_map<char, int> freq;
        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        int res = 0;
        bool OddFreq = false;
        for (auto& it : freq) {
            int f = it.second;
            // Check if the frequency is even
            if (f % 2 == 0) res += f;
            else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                res += f - 1;
                OddFreq = true;
            }
        }
        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (OddFreq) return res + 1;

        return res;
    }
};

