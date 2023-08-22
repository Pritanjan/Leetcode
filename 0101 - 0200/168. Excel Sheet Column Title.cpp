// APPROACH 1

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        char ch;
        
        while(columnNumber--){
            ch = 'A' + columnNumber % 26;
            ans = ch + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};
