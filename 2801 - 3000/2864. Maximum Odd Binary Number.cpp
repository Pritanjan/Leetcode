// A 1 

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt0 = 0, cnt1 = 0;
        for(char c : s) {
            if(c == '0') cnt0++;
            else cnt1++;
        }
        string res = "";
        while(cnt1 > 1) {
            res += '1';
            cnt1--;
        }
        while(cnt0 > 0) {
            res += '0';
            cnt0--;
        }
        res += '1';
        return res;
    }
};






// A 2 

