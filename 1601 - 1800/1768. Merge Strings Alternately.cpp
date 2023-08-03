// APPROACH 1 [ Two Pointers ]

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L1 = 0;
        int L2 = 0;
        string ans;
        
        while((L1 < word1.size()) || (L2 < word2.size())  ){
            if(L1 < word1.size()) ans += word1[L1++];
            if(L2 < word2.size()) ans += word2[L2++];
        }
        return ans  ;
    }
};

// T.C. --> O(s1.size() + s2.size() )
// S.C. --> O(1)


// OR

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L1 = 0;
        int L2 = 0;
        string ans;
        
        while(L1 < word1.size() && L2 < word2.size() ){
            ans += string() + word1[L1++] + word2[L2++];
        }
        return ans + word1.substr(L1) + word2.substr(L2);
    }
};


// OR Using Iterator

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        
        while(it1 != word1.end() || it2 != word2.end()) {
            if(it1 != word1.end()) {
                res += *it1;
                ++it1;
            }
            if(it2 != word2.end()) {
                res += *it2;
                ++it2;
            }
        }        
        return res;
    }
};




// APPROACH 2 [ One Pointers ]

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L1 = 0;
        string ans;
        
        while( L1 < max(word1.size(), word2.size())) {
            if(L1 < word1.size()) ans += word1[L1];
            if(L1 < word2.size()) ans += word2[L1];

            L1++;
        }
        return ans  ;
    }
};

//T.C. --> O(s1.size() + s2.size() )
//S.C. --> O(1)





// APPROACH 3 [ RECURSION ]

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.length() == 0) return word2;
        if(word2.length() == 0) return word1;
        
        string res = "";
        res += word1[0];
        res += mergeAlternately(word2, word1.substr(1));
        return res;
    }
};






// APPROACH 4 

class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string res = "";
        int n = min(s1.length(), s2.length());
        
        for(int i=0; i<n; i++) {
            res += s1[i];
            res += s2[i];
        }
        
        // Add any remaining characters from the longer string
        if(s1.length() > n) res += s1.substr(n);
        else if(s2.length() > n) res += s2.substr(n);
                
        return res;
    }
};

