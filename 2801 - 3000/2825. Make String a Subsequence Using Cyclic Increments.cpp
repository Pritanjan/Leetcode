// APPROACH 0 Brute Force

// try all possible sets of indices and check if the resulting modified string str1 contains str2
// as a subsequence. 
// This approach has an exponential time complexity and is not efficient for larger inputs,
// but it's a simple way to start.

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        for(int j=0; j<(1 << str1.size()); ++j) {
            string tmp = str1;
            for(int i=0; i<str1.size(); ++i) {
                if(j & (1 << i)) tmp[i] = (tmp[i] - 'a' + 1) % 26 + 'a'; // Increment cyclically
            }
            int i = 0, k = 0;
            while(i < tmp.size() && k < str2.size()) {
                if(tmp[i] == str2[k]) ++k;
                ++i;
            }
            if(k == str2.size()) return true;
        }
        return false;
    }
};






// APPROACH 1

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size() > str1.size()) return false;
        int p = 0;
        for(int i=0; i<str1.size(); i++) {
            if(p < str2.size() && str1[i] == str2[p]) p++;
            else if(p < str2.size() && ((str1[i]-'a'+1)%26 + 'a') == str2[p]) p++;
        }        
        return p == str2.size();
    }
};






// APPROACH 2 

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int P = 0;
        for(auto it : str1){
            if(it == str2[P]) P++;
            else {
                auto it2 = it;
                if(it2 == 'z') it2 = 'a';
                else it2++;
                if(it2 == str2[P]) P++;
            }
            if(P == str2.size()) return true;
        }
        return false;
    }
};

