// A 1

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






// A 2

class Solution {
public:
    string convert(string s, int numRow) {
        if(numRow == 1) return s;
        
        vector<string> v(numRow);
        int row = 0;
        int inc = -1;        
        for(int i=0; i<s.size(); i++){
            if(i % (numRow - 1) == 0) inc *= -1;
            v[row].push_back(s[i]);
            row += inc;
        }

        string ans ;
        for(const auto& str : v) {
            ans += str;
        }        
        return ans;
    }
};






// A 3
// simulate and add each character to the corresponding row
// go down -> reach bottom -> go up -> reach top -> go down ...

class Solution {
public:
    string convert(string s, int numRows) {
        // edge case
        if(numRows == 1)
            return s;
        vector<string> rows(numRows);

        // j is the index to track which rows a character should be added to
        // d is the direction: -1 means go up, 1 means go down
        int j = 0, d = 1;
        for (int i = 0; i < s.size(); i++) {
            // add the current character to corresponding row
            rows[j] += s[i];
            // if it reaches to the last row, we need to go up
            if(j == numRows - 1) d = -1;
            // if it reaches to the first row, we need to go down
            else if(j == 0) d = 1;
            // move j pointer
            j += d;
        }

        // // rows would look like below in the first example
        // // ['PAHN', 'APLSIIG', 'YIR']
        // // we use join to build the final answer
        // string res = "";
        // for(int i=0; i<numRows; i++){
        //     res += rows[i];
        // }

        // return res;

        return accumulate(rows.begin(), rows.end(), string{});
    }
};




