// A 1 

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long steps = 0;  
        int wcnt = 0;   
        for(int i=0; i<n; ++i) {
            if (s[i] == '0') steps += wcnt;
            else wcnt++;
        }
        return steps;
    }
};

