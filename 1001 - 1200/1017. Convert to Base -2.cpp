// APPROACH 1

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
    
        string res = "";
        while(n != 0){
            int rem = n % (-2);
            n /= -2;
            if(rem < 0) {
                rem += 2;
                n += 1;
            }
            res += to_string(rem);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// OR


class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
    
        string res = "";
        while(n != 0){
            int rem = n & 1;
            n = -(n >> 1);
            res += to_string(rem);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




// APPROACH 2

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        
        vector<int> res;
        while (n != 0) {
            int remain = abs(n % (-2));
            res.push_back(remain);
            n -= remain;
            n /= -2;
        }
        string binaryStr = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            binaryStr += to_string(res[i]);
        }
        return binaryStr;
    }
};





// APPROACH 3

class Solution {
public:
string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        vector<int> bits(32);
        int carry = n;
        for (int i = 0; i < 32; i++) {
            int val = carry + bits[i];
            bits[i] = val & 1;
            carry = (val - bits[i]) / (-2);
        }
        int pos = 31;
        string res;
        while (pos >= 0 && bits[pos] == 0) {
            pos--;
        }
        while (pos >= 0) {
            res.push_back(bits[pos] + '0');
            pos--;
        }
        return res;
    }
};





// APPROACH 3

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while (n) {
            int c = abs(n % (-2));
            ans = (c == 0 ? '0' : '1') + ans;
            n = (n - c) / (-2);
        }
        return ans;
    }
};






class Solution {
public:
    string baseNeg2(int n) {
        int val = 0x55555555 ^ (0x55555555 - n);
        if (val == 0) {
            return "0";
        }
        string res;
        while (val) {
            res.push_back('0' + (val & 1));
            val >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};





