// APPROACH 1

/*n=numRows
?=2n-2    1                           2n-1                         4n-3
?=        2                     2n-2  2n                    4n-4   4n-2
?=        3               2n-3        2n+1              4n-5       .
?=        .           .               .               .            .
?=        .       n+2                 .           3n               .
?=        n-1 n+1                     3n-3    3n-1                 5n-5
?=2n-2    n                           3n-2                         5n-4
*/

// https://leetcode.com/problems/zigzag-conversion/
// https://leetcode.com/problems/zigzag-conversion/discuss/3435/If-you-are-confused-with-zigzag-patterncome-and-see!

class Solution {
public:
    string convert(string s, int numRow) {
        string ans = "";
        
        if(numRow == 1)
            return s;
        
        int s1, s2;
        
        for(int i=0; i<numRow; i++){
            s1 = (numRow-i-1)*2 ;
            s2 = 2*i;
            int pos = i;
            
            if(pos < s.size())
                ans += s.at(pos);
            while(true){
                pos += s1;
                if(pos >= s.size())
                    break;
                if(s1)
                    ans += s.at(pos);
                pos += s2;
                
                if(pos >= s.size())
                    break;
                if(s2)
                    ans += s.at(pos);
            }
        }
        return ans;
    }
};






// APPROACH 1

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
