// A 1 - Find the Rightmost Odd Digit

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1; i>=0; i--) {
            if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 2

