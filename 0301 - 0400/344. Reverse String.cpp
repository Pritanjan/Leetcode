// https://leetcode.com/problems/reverse-string/submissions/

// APPROACH 1
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin() , s.end() ); 
        return s;
    }
};


// APPROACH 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left  =  0;
        int right = s.size() - 1;
       
        while(left <= right){
            swap(s[left], s[right]);
                left++; right--;
        }   
    }
};

// T.C. O(N)
// S.C. O(1)


// APPROACH 3
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
        // return s;
    }
};








// REVDRSE A WORD 


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "poi";
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        st.push(s[i]);
    }

    string res = "";

    while(!st.empty()){
        res.push_back(st.top());

        st.pop();
    }

    cout << res;
}

// T.C. O(N)
// S.C. O(N)  -> due to stack 





