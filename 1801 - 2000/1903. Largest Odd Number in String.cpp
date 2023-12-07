// A 1 - Find the Rightmost Odd Digit

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1; i>=0; i--) {
            if(int(num[i]) % 2) {
            // if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 2

class Solution {
public:
    string largestOddNumber(string num) {
        int idx=0;
        for(int i=num.size()-1; i>=0; i--) {
            if((num[i]-48) % 2 == 1) {
                idx = i+1;
                break;
           }
       }
       return num.substr(0, idx);
    }
};






// A 3

class Solution {
public:
    string largestOddNumber(string num) {
       int n =-1; 
        for(int i=0; i<num.size(); i++) {
            int a = int(num[i]-'0'); 
            if(a % 2) n = i;
        }
        string ans =""; 
        for(int i=0; i<=n; i++) {
            ans += num[i]; 
        }              
        return ans;
    }
};







// A 4 

class Solution1 {
public:
    string largestOddNumber(string num) {
        string s = "";
        int c = 0;
        if(stoi(num) % 2 != 0) return num;
        for(int i=0; i<num.size(); i++) {
            if((num[i]-'0') % 2 != 0) {
                s += num[i];
            }
        }
        return s;
    }
};


