// A1 - Using Arrays

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};        
        for(int i=0; num != 0; i++) {
            while(num >= ans[i]) {
                num = num - ans[i];
                ret = ret + str[i];
            }
        }
        return ret;
    }
};






// A2 - Using a Map

class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> mp;
        mp[1000] = "M";
        mp[900] = "CM";
        mp[500] = "D";
        mp[400] = "CD";
        mp[100] = "C";
        mp[90] = "XC";
        mp[50] = "L";
        mp[40] = "XL";
        mp[10] = "X";
        mp[9] = "IX";
        mp[5] = "V";
        mp[4] = "IV";
        mp[1] = "I";

        string res = "";
        for(auto& i : mp) {
            while(num >= i.first) {
                num -= i.first;
                res += i.second;
            }
        }
        return res;
    }
};
