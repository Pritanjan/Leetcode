// APPROACH 1

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
            if(isVowel(s[R])) {
                vowels++;
            }

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





// APPROACH 2
