// A 1 

class Solution {
public:
    int minOperations(string s) {
        int idx1 = 0, idx0 = 0;
        for(int i=0; i<s.size(); i++) {
            if(i % 2 == 0) {
                s[i] == '0' ? idx1++ : idx0++;
            }
            else {
                s[i] == '1' ? idx1++ : idx0++;                
            }
        }
        return min(idx1, idx0);
    }
};






// A 2 

class Solution {
public:
    int minOperations(string s) {
        int idx = 0;
        for(int i=0; i<s.size(); i++) {
            if(i % 2 == 0) {
                if(s[i] == '1') idx++;
            }
            else {
                if(s[i] == '0') idx++;
            }
        }
        return min(idx, (int)s.size() - idx);
    }
};






// A 3 

