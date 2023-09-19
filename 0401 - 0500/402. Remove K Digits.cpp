//  A 1 - Using Stack

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        // if the curr element is less than prev then remove the prev element else push it into stack
        for(char c : num) {
            while(k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // for cases like "456" where every num[i] > num.top()
        while(k-- > 0) st.pop();
        string res;
        while(!st.empty()) {
            // res = s.top() + res;
            res.push_back(st.top());     // pushing stack top to string
            st.pop();    // pop the top element
        }

        reverse(res.begin(), res.end()); // reverse the string         
        int idx = 0;
        while(idx < res.size() - 1 && res[idx] == '0') idx++;
        res = res.substr(idx);
        
        return res.length() == 0 ? "0" : res;
    }
};

// T.C. ->  O(N)
// S.C. -> O(N)






// A 2

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans  = "";        
        for(char c : num){
            while(ans.size() && ans.back() > c && k) {
                ans.pop_back();
                k--;
            }            
            if(ans.size() || c!='0') ans.push_back(c);
        }
        
        while(ans.size() && k--) ans.pop_back();
        return ans == "" ? "0" :ans;
    }
};

// Time complexity: O(n), where n is the length of the input string "num". 
// The algorithm iterates through the input string once.

// Space complexity: O(n), where n is the length of the input string "num".
// The space used by the output string "ans" is at most equal to the length of the input string.






//  A 3

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";        
        for(int i=0; i<num.size() - 1 && k > 0; i++){
            if(num[i] > num[i+1] && k > 0){ 
                k--;
                num.erase(i, 1);
                i--;
                if(i >= 0) i--;
            }
        }
        
        while(k-- > 0 && num.size() > 0) num.erase(num.size() - 1, 1);
        while(num.size() > 0 && num[0] == '0') num.erase(0, 1);
        if(num.size() == 0) return "0";
        return num;
    }
};

// Time complexity of the given function is O(nk), where n is the length of the input string "num".
// The while loop for removing digits at the end takes O(k) time and the for loop takes O(nk) 
// time in the worst case.

// Space complexity of the function is O(n), which is the space required to store the input 
// string "num" and the modified string during the execution of the function.






// A 4
