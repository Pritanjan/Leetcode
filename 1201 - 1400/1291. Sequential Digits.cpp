// https://leetcode.com/problems/sequential-digits/solutions/4666207/c-0ms-o-1-time-space-solution/

// A 1 

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";

        for(int l=1; l<=9; ++l) {
            for(int  s=0; s+l<=9; ++s) {
                string sub = digits.substr(s, l);
                int num = stoi(sub);
                
                if(num >= low && num <= high) res.push_back(num);
                // else if(num > high) return res; 
            }
        }
        return res;
    }
};

// T.C. --> O(1)
// S.C. --> O(1)






// A 2  LC copy

class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int> q;
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int> ret;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(f <= h && f >= l) {
                ret.push_back(f);
            }
            if(f > h)
                break;
            int num = f % 10;
            if(num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};


