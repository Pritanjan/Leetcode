// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRow) {
        
        if(numRow == 1)
            return s;
        
        vector<string> v(numRow);
        int row = 0;
        int inc = -1;
        
        for(int i=0; i<s.size(); i++){
            if(i % (numRow - 1) == 0)
                inc *= -1;
            v[row].push_back(s[i]);
            row += inc;
        }
        string ans ;
        for(const auto& str:v )
            ans += str;
        
        return ans;
    }
};
