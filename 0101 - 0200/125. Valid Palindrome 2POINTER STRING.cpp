// APPROACH 1

class Solution {
public:    
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r){
            if(!isalnum(s[l])) {
                l++;
            }
            else if (!isalnum(s[r])){
                r--;
            }
            else{
                if(tolower(s[l++]) != tolower(s[r--])){
                    return false;
                    // l++;
                    // r--;
                    
                }
            }
        }
        return true;
    }
};








// APPROACH 2

class Solution {
public:
    bool isValid(char ch){
        if((ch >= 'a' and ch <='z') or (ch >= 'A' and ch <='Z') or (ch >= '0' and ch <='9'))
            return 1;
        return 0;
    }
    
    // convert upper to lower but if lower it remains unchanged
    char toLower(char ch){
        if((ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9'))
            return ch;
        else{
            char temp = ch - 'A' +'a';
            return temp;
        }
    }
    
    bool checkPalindrome(string s){
        int L = 0;
        int R = s.size() - 1;
        
        while(L <= R){
            if(s[L] != s[R]){
                return 0;
            }
            else{
                L++;
                R--;
            }
        }
        return 1;
    }
    
    bool isPalindrome(string s) {
        string temp = "";
        
        // removing extra charracter
        for(int i=0; i<s.size(); i++){
            if(isValid(s[i]))
                temp.push_back(s[i]);
        }
        
        // converting to lower case
        for(int i=0; i<temp.size(); i++){
            temp[i] = toLower(temp[i]);
        }
        // check palidrome 
        return checkPalindrome(temp);
    }
};












// APPROACH 3

class Solution {
public:
    bool isPalindrome(std::string s) {
        vector<char> a;
        for(char c : s) {
            if (isalpha(c) || isdigit(c)) {
                a.push_back(tolower(c));
            }
        }

        vector<char> v = a;
        reverse(v.begin(), v.end());
        return a == v;
    }
};



