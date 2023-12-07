// A 1

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        int j = 0;
        for(int i = 0; i < min({n1, n2, n3}) && s1[i] == s2[i] && s2[i] == s3[i]; ++i) {
            j = i+1;
        }
        
        int op = n1+n2+n3 - 3*j;
        if(j == 0) return -1;
        return op;
    }
};






// A 2


