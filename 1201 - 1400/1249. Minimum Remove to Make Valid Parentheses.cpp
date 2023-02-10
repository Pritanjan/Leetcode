// APPROACH 1 USING STACK & VECTOR BOTH

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        vector<bool> remove(s.size(), false);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }else if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else remove[i] = true;
            }
        }

        while(!stk.empty()) {
            remove[stk.top()] = true;
            stk.pop();
        }
        
        string res = "";
        for(int i=0; i<s.size(); i++){
            if(!remove[i]){
                res += s[i];
            }
        }
        return res;
    }
};





// APPROACH 2 ONLY USING STACK

class Solution {
public:
    string minRemoveToMakeValid(string s) {
         stack<int>st; // helper stack for finding matching parentheses
        
        for(int i=0;i<s.length();++i){
            if(s[i]=='('){ // for open parentheses push into stack
                st.push(i);
            }
            else if(s[i]==')'){ // for closing parentheses
                // if no matching previous open parentheses found, we need to remove the index of that open parentheses from "s" so for now we are marking it with special character '#'
                if(st.empty()){ 
                    s[i]='#';
                }
                else{
                    // if matching open parentheses found remove that from the stack
                    st.pop();
                }
            }
        }

        // if stack is not empty, that means it contains open parentheses indexes which don't have any matching closing parentheses
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        
        // LINE 66-68 & 70-76 & 78-83 ARE SAME
        // s.erase(remove(s.begin(),s.end(),'*'),s.end());
        // return s;

        // LINE 66-68 & 70-76 & 78-83 ARE SAME 
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#'){ // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }
        
        // LINE 66-68 & 70-76 & 78-83 ARE SAME
        // string ans="";
        // for(auto i:s){
        //     if(i!='@')
        //     ans.push_back(i);
        // }

        return ans;
    }
};




// This code implements a solution to remove the minimum number of parentheses from a 
// string so that the resulting string is valid.

// 1. It uses a stack to keep track of the indices of the opening parentheses in
//    the input string s.

// 2. For each character in the input string,
//    if it is an opening parenthesis, its index is pushed onto the stack. 
//    If it is a  closing parenthesis, the code checks if the stack is empty or not.

// 3. If the stack is not empty, it pops the topmost index from the stack (which 
//    corresponds to the matching opening parenthesis for the current closing parenthesis).

// 4. If the stack is empty, it means that there is no matching opening parenthesis 
//    for the current closing parenthesis, and so it marks the current index as a
//    removal index by setting its corresponding value in the remove vector to true.

// 5. After the first pass,
//    stack contains indices of unmatching opening parentheses that need to be removed. 
//    These indices are popped from the stack and their corresponding values in the
//    remove vector are set to true.

// 6. Finally, a loop is run over the input string, and for each character whose index 
//    is not marked for removal, it is added to the result string res.

// 7. The final result string res is returned.

// Time complexity  : O(n), where n is the length of the input string s. 
// Because it performs two linear scans through the input string, each taking O(n) time.

// Space complexity : O(n), where n is the length of the input string s. 
// Because we are using a stack to store indices of the opening parentheses, and
// a boolean array to store information about which characters should be removed.
// The maximum size of the stack is equal to the number of opening parentheses, and
// the size of the boolean array is equal to the length of the input string.





// APPROACH 3

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') st.push({s[i], i});
            else if(s[i] == ')') {
                if(!st.empty() && st.top().first == '(') st.pop();
                else st.push({s[i], i});
                
            }         
        }

        while (!st.empty()) {    
            s.erase(s.begin() + st.top().second);
            st.pop();
        }

        return s;
    }
};


// time complexity : O(n), where n is the length of the input string. 
// Because we are iterating through the entire string once, and the stack operations
// (push, pop, and empty) all take constant time.

// space complexity :  O(m), where m is the number of invalid parentheses in the input string. 
// This is because we are using a stack to store the indices of invalid parentheses, 
// and the maximum number of indices that can be stored in the stack is m.








// APPROACH 3 SAME AS ABOVE ONLY DIFF ON IS STACK
    
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty()){
                    s.erase(s.begin() + i);
                    i--;
                }
                else st.pop(); 
            }
        }
        
        while(!st.empty()){
            s.erase(s.begin()+st.top());
            st.pop();
        }

        return s;
    }
};





