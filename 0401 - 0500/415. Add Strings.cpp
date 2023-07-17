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




