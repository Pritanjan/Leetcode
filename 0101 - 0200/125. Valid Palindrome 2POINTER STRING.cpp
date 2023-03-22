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








// APPROACH 4

class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                s1+=s[i];
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                s1+=s[i]+32;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                s1+=s[i];
            }
        }
        
        int j=s1.size()-1;
        bool f=true;
        for(int i=0;i<s1.size();i++){
            if(i>j) {
                break;
            }
            if(s1[i]!=s1[j]){
                f=false;
                break;}
                j--;
            
        }
        return f;
    }
};






