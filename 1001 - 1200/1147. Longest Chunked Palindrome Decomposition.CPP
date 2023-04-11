class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.length();
        if(n==0) return 0;
        for(int i=1;i<=text.size()/2;i++) 
            if(text.substr(0,i)==text.substr(text.size()-i,i)) 
                return longestDecomposition(text.substr(i,text.size()-2*i))+2;
        return min(1,int(text.size()));
    }
};




class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        if(n == 0) return 0;

        for(int i = 1; i <= n/2 ; i++){
            if(text.substr(0,i) == text.substr(n - i,i)){
                return 2 + longestDecomposition(text.substr(i,n - 2 * i));
            }
        }

        return 1;
    }
};



class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
        for(int i=n-1;i>0;i--) {
            if(text[i]==text[0]&&text.substr(0,n-i)==text.substr(i)) {
                if(2*i>n) return 2+longestDecomposition(text.substr(n-i,2*i-n));
                else if(2*i==n) return 2;
                else return 1;
            }
        }
        return 1;
    }
};





class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size(), ans = 0;
        vector<char> prefix, suffix;
        for (int i = 0; i < n / 2; i++) {
            prefix.push_back(text[i]);
            suffix.push_back(text[n - i - 1]);
            if (prefix == vector<char>(suffix.rbegin(), suffix.rend())) {
                ans += 2;
                prefix.clear();
                suffix.clear();
            }
        }
        return ans + (n % 2 || prefix.size() > 0 ? 1 : 0);
    }
};




class Solution {
public:
    int longestDecomposition(string s) {
        int n = s.size(), ans = 1;
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        for (int i = 1; i <= n / 2; i++) {
            if (s.substr(0, i) == s.substr(n - i)) {
                ans = max(ans, 2 + longestDecomposition(s.substr(i, n - 2 * i)));
            }
        }
        return ans;
    }
};



class Solution {
public:
    int longestDecomposition(string text) {
        return find(text, 0, text.length() - 1);
    }
    int find(string s, int l, int r) {
        if (r - l < 1) { return r - l + 1; }
        for (int i = 1; i <= (r - l + 1) / 2; i++) {
            if (s.substr(l, i) == s.substr(r - i + 1, i)) {
                return 2 + find(s, l + i, r - i);
            }
        }
        return 1;
    }

};



class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        for (int i = n - 1; i > 0; i--) {
            if (text[i] == text[0] && text.substr(0, n - i) == text.substr(i)) {
                if (2 * i > n) {
                    return 2 + longestDecomposition(text.substr(n - i, 2 * i - n));
                }
                else if (2 * i == n) {
                    return 2;
                }
                else {
                    return 1;
                }
            }
        }
        return 1;
    }
};

