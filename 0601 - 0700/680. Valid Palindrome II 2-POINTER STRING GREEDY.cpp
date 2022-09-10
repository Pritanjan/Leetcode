// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    
    bool isPalindrome (string s, int left, int right){
        while(left < right){
            if(s[left] == s[right] ) {
                right--;
                left++;
            }
            else
                return 0;
        }
        return 1;
    }
    
    
    bool validPalindrome(string s) {
        int left  = 0;
        int right = s.size() - 1;
        
        while(left < right){
            if(s[left] == s[right]){
                right--;
                left++;
            }
            else{
                return isPalindrome (s, left, right-1) or isPalindrome (s, left+1, right);
            }
        }
        return true;
        
    }
};


// APPROACH

// LEFT AT 0TH  & RIGHT AT LAST

// CHECK IF LEFT & RIGHT ARE EQUAL  THEN JUST DO RIGHT-- & LEFT++

// IF NOT EQUAL THEN DO 2 THINGS 

// 1 . SKIP THE RIGHT INDEX CHARRACTER & CHECK IF LEFT & RIGHT - 1 ARE A PALINDROME OR NOT  
// 2.  SKIP THE LEFT  INDEX CHARRACTER & CHECK IF LEFT + 1 & RIGHT  ARE A PALINDROME OR NOT













