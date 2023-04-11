// APPROACH 1 [ STRINGS ]

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







// APPROACH 2 [ USING STACK ]


// Use a stack to store the characters.
// Pop one character off the stack at each star. 
// Otherwise, we push the character onto the stack.


class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(auto i : s){
            if(i == '*') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(i);
            }
        }

        string res;
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







// APPROACH 3 [ 2 POINTER ]


class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                ch[j++] = s[i];
            }
        }

        string answer = "";
        for (int i = 0; i < j; i++) {
            answer.push_back(ch[i]);
        }

        return answer;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)


