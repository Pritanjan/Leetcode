// A 1 - Using Sorting 

class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&](char a, char b) {
            return order.find(a) < order.find(b);
        });
        return s;
    }
};






// A 2

class Solution {
public:
    static string str;
    static bool compare(char char1, char char2) {
        return (str.find(char1) < str.find(char2));
    }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;






// A 3 

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> d(26);
        for (int i = 0; i < order.size(); i++) {
            d[order[i] - 'a'] = i;
        }

        int n = s.length();
        vector<char> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = s[i];
        }

        sort(b.begin(), b.end(), [&](auto a, auto b) {
            return d[a - 'a'] < d[b - 'a'];
        });

        string o = "";
        for (char c : b) {
            o.push_back(c);
        }
        return o;
    }
};
