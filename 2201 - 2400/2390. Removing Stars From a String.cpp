// A 1 [ STRINGS ]

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '*')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 2 [ USING STACK ]

// Use a stack to store the characters.
// Pop one character off the stack at each star. 
// Otherwise, we push the character onto the stack.

class Solution {
public:
    string removeStars(string s) {
        stack<int> stk;
        for(auto i : s){
            if(i == '*') stk.pop();
            else stk.push(i);
        }

        string res = "";
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }        
        reverse(res.begin(), res.end());
        return res;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 3 [ 2 POINTER ]

class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') j--;
            else ch[j++] = s[i];
        }

        string ans = "";
        for (int i = 0; i < j; i++) {
            ans.push_back(ch[i]);
        }
        return ans;
    }
};


// OR


class Solution {
public:
    string removeStars(string s) {
        vector<pair<char, int>> ch;
        for(char c : s) {
            if(c == '*') ch.pop_back();
            else ch.push_back({c, ch.size()});
        }

        string res;
        for(auto& p : ch) {
            res += p.first;
        }
        return res;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)






// A 4

