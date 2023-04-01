// APPROACH 1

class Solution {
public:
    string maskPII(string s) {
        int pos = s.find('@');
        if(pos != -1){
            string ans;
            ans += s[0] >= 97 ? s[0] : s[0] + 32;
            ans += "*****";
            ans += s[pos-1] >= 97 ? s[pos-1] : s[pos-1] + 32;
            ans += s.substr(pos, s.size() - pos);
            pos = 8;
            while(pos < ans.size()){
                if(ans[pos] != '.' && ans[pos] < 97) ans[pos] += 32;
                pos++;
            }
            return ans;
        }
        string tmp;
        pos = 0;
        while(pos < s.size()){
            if(s[pos] >= 48 && s[pos] <= 57) tmp += s[pos];
            pos++;
        }
        string ans;
        if(tmp.size() == 10) ans += "***-***-";
        else if(tmp.size() == 11) ans += "+*-***-***-";
        else if(tmp.size() == 12) ans += "+**-***-***-";
        else ans += "+***-***-***-";
        ans += tmp.substr(tmp.size()-4,4);
        return ans;
    }
};





// APPROACH 2

class Solution {
public:
    string maskPII(string S) {
        int idx = S.find("@");
        if (idx != -1) {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
            string tmp = S.substr(0, idx);
            return tmp[0] + string("*****") + tmp[tmp.size() - 1] + S.substr(idx);
        }
        else {
            string digits;
            for (char c : S) {
                if (isdigit(c)) {
                    digits.push_back(c);
                }
            }
            int n = digits.size();
            if (n == 10) {
                return string("***-***-") + digits.substr(n - 4);
            }
            else {
                return string("+") + string(n - 10, '*') + string("-***-***-") + digits.substr(n - 4);
            }
        }
    }
};

int main() {
    Solution sol;
    string S1 = "LeetCode@LeetCode.com";
    string S2 = "1(234)567-890";
    cout << sol.maskPII(S1) << endl;  // Output: l*****e@leetcode.com
    cout << sol.maskPII(S2) << endl;  // Output: ***-***-7890
    return 0;
}




// APPROACH 3 [ Simulation ]

// We judge first s Whether it's an email address or a phone number. Obviously, if s in characters 
// ‘@’, then it is a mail, otherwise it is a phone number.

// If s is mail, we will s target ‘@’ The first and last characters are retained in the previous 
// part, with the middle used “*****"  instead, and converts the entire string to lowercase.

// If s is the phone number, we only keep it s all numbers. Use first will last 10 The bit local no
// becomes  “***-***-XXXX" form, and then check s Whether there are additional international no.
// If so, add the international number before ‘+’ and add to the very front of the local no.

// (i)    If there is 10 bits, prefixed with a bit-empty string.
// (ii)   If there is 11 digits, prefixed with prefixes “+*-"
// (iii)  If there is 12 digits, without prefix “+**-"
// (iv)   If there is 13 digits, without prefix “+**"


class Solution {
public:
    vector<string> country = {"", "+*-", "+**-", "+***-"};

    string maskPII(string s) {
        string res;
        int at = s.find("@");
        if (at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }
};


// T.C. -->  O(n),  n is the length of the string.
// S.C. -->  O(n),  n is the length of the string.





// APPROACH 4 Simulation
    
class Solution {
    public String maskPII(String S) {
        int atIndex = S.indexOf('@');
        if (atIndex >= 0) { // email
            return (S.substring(0, 1) + "*****" + S.substring(atIndex - 1)).toLowerCase();
        } else { // phone
            String digits = S.replaceAll("\\D+", "");
            String local = "***-***-" + digits.substring(digits.length() - 4);
            if (digits.length() == 10) return local;
            String ans = "+";
            for (int i = 0; i < digits.length() - 10; ++i)
                ans += "*";
            return ans + "-" + local;
        }
    }
}


// T.C. -->  O(n),  n is the length of the string.
// S.C. -->  O(1)

