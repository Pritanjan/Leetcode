// APPRAOCH 1  --> 2 POINTER

class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";
        int i = num1.size() - 1; 
        int j = num2.size() - 1;
        int carry = 0;
        
        while(i >= 0 or j >= 0 or carry > 0){
            if(i >= 0){
                carry += num1[i] - '0';
                i--;
            }
            if(j >= 0){
                carry += num2[j] - '0';
                j--;
            }
            s += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

// Time: O(M+N), where M <= 10^4 is length of num1, N <= 10^4 is length of num2.
// Extra Space (without counting output as space): O(1)


// OR


class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int carry = 0;
        string res = "";
        
        // Convert strings to character arrays
        const char* str1 = num1.c_str();
        const char* str2 = num2.c_str();
        
        // Pointers to the last character of each string
        int i = n - 1;
        int j = m - 1;
        
        // Iterate over the strings from right to left
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if(i >= 0) sum += str1[i--] - '0';
            if(j >= 0) sum += str2[j--] - '0';
            
            carry = sum / 10;
            sum = sum % 10;
            res = char(sum + '0') + res;
        }
        return res;
    }
};





// APPROACH 2  [ Reverse and Pad ]

// Reverse both input strings and pad them with leading zeros to ensure they have same length.
// Then, do addition of digit by digit from left to right, keeping track of the carry.
// This approach simplifies the addition logic as both strings have the same length.


class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int carry = 0;
        string res = "";

        // Reverse the strings
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Pad the shorter string with leading zeros
        int maxLength = max(n, m);
        num1 += string(maxLength - n, '0');
        num2 += string(maxLength - m, '0');

        // Iterate from left to right
        for(int i=0; i<maxLength; i++) {
            int sum = carry + (num1[i] - '0') + (num2[i] - '0');
            carry = sum / 10;
            sum = sum % 10;
            res += char(sum + '0');
        }

        // Add the remaining carry, if any
        if(carry > 0) res += char(carry + '0');

        // Reverse the result to get the correct order
        reverse(res.begin(), res.end());

        return res;
    }
};





// APPRAOCH 3 [ Recursive Approach ]

// Use recursion to add the digits of the 2 strings from right to left, similarly to the manual addition.
// Base case --> when both strings are empty, and
// recursive step would involve adding the last digits and recursively adding the remaining parts.


class Solution {
public:
    string recursion(string num1, string num2, int i, int j, int carry) {
        if(i < 0 && j < 0) {
            if(carry > 0) return to_string(carry);
            else return "";
        }

        int sum = carry;
        if(i >= 0) sum += num1[i] - '0';
        if(j >= 0) sum += num2[j] - '0';

        carry = sum / 10;
        sum = sum % 10;

        return recursion(num1, num2, i - 1, j - 1, carry) + char(sum + '0');
    }

    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        return addStringsRecursive(num1, num2, n - 1, m - 1, 0);
    }
};



