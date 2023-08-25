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





// A 3  - Using Struct

class Solution {
public:
    struct RomanSymbol {
        int value;
        const char* symbol;
    };

    string intToRoman(int num) {
        const RomanSymbol symbols[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},  {1, "I"}
        };

        string res = "";
        for(const RomanSymbol& symbol : symbols) {
            while(num >= symbol.value) {
                num -= symbol.value;
                res += symbol.symbol;
            }
        }
        return res;
    }
};






// A 4 - Recusrion

class Solution {
public:
    string intToRoman(int num) {
        if(num >= 1000) return "M"   + intToRoman(num - 1000);
        if(num >= 900)  return "CM"  + intToRoman(num - 900);
        if(num >= 500)  return "D"   + intToRoman(num - 500);
        if(num >= 400)  return "CD"  + intToRoman(num - 400);
        if(num >= 100)  return "C"   + intToRoman(num - 100);
        if(num >= 90)   return "XC"  + intToRoman(num - 90);
        if(num >= 50)   return "L"   + intToRoman(num - 50);
        if(num >= 40)   return "XL"  + intToRoman(num - 40);
        if(num >= 10)   return "X"   + intToRoman(num - 10);
        if(num >= 9)    return "IX"  + intToRoman(num - 9);
        if(num >= 5)    return "V"   + intToRoman(num - 5);
        if(num >= 4)    return "IV"  + intToRoman(num - 4);
        if(num >= 1)    return "I"   + intToRoman(num - 1);
        return "";
    }
};


// OR


class Solution {
public:
    string recursion(int num, const vector<int>& val, vector<string>& symb, size_t idx) {
        if(num == 0) return "";
        if(num >= val[idx]) return symb[idx] + recursion(num - val[idx], val, symb, idx);
        else return recursion(num, val, symb, idx+1);
    }

    string intToRoman(int num) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        return recursion(num, val, symb, 0);
    }
};


// OR


class Solution {
public:
    string recursion(int num, const vector<pair<int, string>>& symbols, size_t idx) {
        if(num == 0) return "";
        if(num >= symbols[idx].first) return symbols[idx].second + recursion(num - symbols[idx].first, symbols, idx);
        else return recursion(num, symbols, idx+1);
    }

    string intToRoman(int num) {
        vector<pair<int, string>> symbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},  {1, "I"}
        };
        return recursion(num, symbols, 0);
    }           
};






// A5

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        while(num > 0) {
            if(num >= 1000) {
                res += "M";
                num -= 1000;
            } 
            else if(num >= 900) {
                res += "CM";
                num -= 900;
            } 
            else if(num >= 500) {
                res += "D";
                num -= 500;
            } 
            else if(num >= 400) {
                res += "CD";
                num -= 400;
            }
            else if(num >= 100) {
                res += "C";
                num -= 100;
            } 
            else if(num >= 90) {
                res += "XC";
                num -= 90;
            }
            else if(num >= 50) {
                res += "L";
                num -= 50;
            }
            else if(num >= 40) {
                res += "XL";
                num -= 40;
            }
            else if(num >= 10) {
                res += "X";
                num -= 10;
            }
            else if(num >= 9) {
                res += "IX";
                num -= 9;
            }
            else if(num >= 5) {
                res += "V";
                num -= 5;
            }
            else if(num >= 4) {
                res += "IV";
                num -= 4;
            } 
            else {
                res += "I";
                num -= 1;
            }
        }
        return res;
    }
};


