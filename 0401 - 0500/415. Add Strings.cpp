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


Time: O(M+N), where M <= 10^4 is length of num1, N <= 10^4 is length of num2.
Extra Space (without counting output as space): O(1)


