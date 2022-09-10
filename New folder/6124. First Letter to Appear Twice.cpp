class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> ust;
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(ust.find(c) != ust.end())
                return c;
            else{
                ust.insert(c);
            }
        }
        
        return '\0';
    }
};

//T.C. O(N)
//S.C. O(n)

// approach 2
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char ch : s)
            if(++v[ch- 'a'] == 2)
                return ch;
        
        return 0;
    }
};
