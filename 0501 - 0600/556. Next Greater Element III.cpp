// A 1 - Brute Force

class Solution {
public:
    int nextGreaterElement(int n) {
        auto num = to_string(n);
        next_permutation(num.begin(), num.end());
        auto ans = stoll(num);
        return (ans <= n or ans > INT_MAX) ? -1 : ans;
    }
};


// OR
// Without using STL

#define ll long long
class Solution {
public:
    void nextPermutation(string &nums){
        ll int i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]) break;
        }

        ll int j=nums.size()-1;
        if(i >= 0) {
            while(nums[j] <= nums[i]) j--;
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }

    int nextGreaterElement(int n) {
        auto num = to_string(n);
        nextPermutation(num);
        auto ans = stoll(num);
        return (ans <= n or ans > INT_MAX) ? -1 : ans;
    }    
};





// A 1 - use set

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        set<int> s_set(s.begin(), s.end());
        while(next_permutation(s.begin(), s.end())) {
            long long res = stoll(s);
            if (res > INT_MAX || res <= n) continue;
            return res;
        }        
        return -1;
    }       
};




// A 2 - using stack

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        stack<int> st;
        
        int i = s.size() - 2;
        while(i >= 0 && s[i] >= s[i + 1]) {
            st.push(s[i] - '0');
            i--;
        }
        
        if(i < 0) return -1;
        
        int j = s.size() - 1;
        while(!st.empty() && st.top() <= s[i] - '0') {
            st.pop();
        }
        
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        
        long long res = stoll(s);
        return (res > INT_MAX) ? -1 : res;
    }     
};





// A 3 

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int m = s.length();
        int j = m - 2;
        while (j >= 0 && s[j] >= s[j + 1])
            j--;
        if (j < 0) {
            return -1;
        }
        int i = m - 1;
        while (i >= j && s[i] <= s[j]) {
            i--;
        }
        swap(s[i], s[j]);
        sort(s.begin() + j + 1, s.end());
        long long num = stoll(s);
        if (num > INT_MAX)
            return -1;
        return num;
    }
};


