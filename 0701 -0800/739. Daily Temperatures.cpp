// A 0 - Brute Force 

// TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(temp[i] < temp[j]) {
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};


// Optimised


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        for(int i=n-2; i>=0; --i) {
            for(int j=i+1; j<n; j += ans[j]) {
                if(temp[j] > temp[i]) {
                    ans[i] = j - i;
                    break;
                }
                else if(ans[j] == 0) break;
            }
        }
        return ans;
    }
};






// A 1 - Using Stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size(); 
        stack<int> st;
        st.push(0);
        vector<int> ans(n,0);
        for(int i=1; i<n; i++){
            while(!st.empty() && temp[i] > temp[st.top()] ){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};






// A 2 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);        
        for(int i=n-1; i>=0; --i){
            int j = i+1;
            while(j < n && temp[i] >= temp[j] ){
                ans[j] > 0 ? j = j + ans[j] : j = n;
            }
            if(j < n)
                ans[i] = j - i;
        }
        return ans;
    }
}; 






// A 3 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int s[1 << 17];
        int j = 0;
        int n = t.size();
        for(int i=0; i<n; i++) {
            while(j != 0 && t[s[j-1]] < t[i]) {
                j--;
                t[s[j]] = i - s[j];
            }
            s[j] = i;
            j++;
        }
        while(j != 0) {
            j--;
            t[s[j]] = 0; 
        }        
        return t;
    }
};






// A 4 
