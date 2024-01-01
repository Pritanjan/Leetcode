// A 1 - Sorting & 2 Pointer

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(j < s.size() && i < g.size()) {
            if(s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};


// OR


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int res = 0;
        while(i < g.size()) {
            auto it = lower_bound(s.begin(), s.end(), g[i]);
            if(it != s.end()) {
                res++;
                s.erase(it);
            }
            i++;
        }
        return res;
    }
};



// A 2  Use priority_queue

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> greed(g.begin(), g.end());
        priority_queue<int, vector<int>, greater<int>> size(s.begin(), s.end());

        int res = 0;
        while(!greed.empty() && !size.empty()) {
            if(size.top() >= greed.top()) {
                res++;
                greed.pop();
            }
            size.pop();
        }
        return res;
    }
};






// A 3 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> mst(s.begin(), s.end());
        int res = 0;
        for(auto greed : g) {
            auto it = mst.lower_bound(greed);
            if(it != mst.end()) {
                res++;
                mst.erase(it);
            }
        }
        return res;
    }
};






// A 4 - Recursion

// Wrong
// class Solution {
// public:
//     int recursion(vector<int>& g, vector<int>& s, int gIdx, int sIdx) {
//         if(gIdx == g.size() || sIdx == s.size()) return 0;
//         if(s[sIdx] >= g[gIdx]) return 1 + recursion(g, s, gIdx+1, sIdx+1);
//         else return recursion(g, s, gIdx, sIdx + 1);
//     }

//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         return recursion(g, s, 0, 0);
//     }
// };


// Correct
class Solution {
public:
    int recursion(vector<int>& g, vector<int>& s, int gIdx, int sIdx) {
        if (gIdx == g.size() || sIdx == s.size()) return 0;

        if (s[sIdx] >= g[gIdx]) {
            // If the current cookie is large enough for the current child,
            // consider assigning it and move to the next child and cookie.
            return 1 + recursion(g, s, gIdx + 1, sIdx + 1);
        } else {
            // If the current cookie is too small for the current child,
            // try the next larger cookie with the same child.
            return recursion(g, s, gIdx, sIdx + 1);
        }
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays before starting the recursion.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        return recursion(g, s, 0, 0);
    }
};
