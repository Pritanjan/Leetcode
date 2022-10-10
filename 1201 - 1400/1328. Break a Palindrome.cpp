[1328. Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/)
##### APPROACH 1 

**Explanation**
1. If the length of  string is `1`, then return empty string as it is not possible to break the palindrome with length 1 or to make a one character string not a palindrome.

2. Traverse through first half of the string and find the first letter that is not equal to ‘a’ in the first half of the string and replace that with ‘a’. It is done to ensures that string is lexicographically smallest non palindrome.

3. At last, check the edge case where if the palindrome comprises of only letter ‘a’, and if true replace the last letter with ‘b’ which ensures to give the lexicographically smallest non palindrome.

**C++**

```

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        // if size is less than or equal to 1 then it is palidrome
        if(n == 1)
            return "";
        for(int i=0; i<n/2; i++){
            // replace first non  'a' charracter to get lexigraphically smallest word
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';    // also line 19 & 20 can be use
        
        return palindrome;
    }
};

```

<br>

**JAVA**

```

class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        
        // if size is less than or equal to 1 then it is palidrome
        if(n == 1)
            return "";
        char[] ch = palindrome.toCharArray();
        
        for(int i=0; i<n/2; i++){
            // replace first non  'a' charracter to get lexigraphically smallest word
            if(ch[i] != 'a'){
                ch[i] = 'a';
                return String.valueOf(ch);
            }
        }
        
        ch[n - 1] = 'b';
        
        return new String(ch);
        
    }
}

```

<br>

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  ` O(N) `
* **Space Complexity : -**  ` O(N) `

<hr><br>
