// Count the occurence of vowel in the first half part and the second half part and then compare them.

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt1 = 0;
        for(int i=0; i<n/2; i++){
            if(s[i] == 'a' or s[i] == 'e'  or s[i] == 'i'  or s[i] == 'o'  or s[i] == 'u' or s[i] == 'A' or s[i] == 'E'  or s[i] == 'I'  or s[i] == 'O'  or s[i] == 'U')
                cnt1++;
        }
        
        cout << cnt1;
        int cnt2 = 0;
        for(int i=(n/2); i<n; i++){
            if(s[i] == 'a' or s[i] == 'e'  or s[i] == 'i'  or s[i] == 'o'  or s[i] == 'u' or s[i] == 'A' or s[i] == 'E'  or s[i] == 'I'  or s[i] == 'O'  or s[i] == 'U')
                cnt2++;
        }
        
        if(cnt2 == cnt1)
            return true;
        return false;
    }
};






