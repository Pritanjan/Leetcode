// https://leetcode.com/problems/number-of-segments-in-a-string/

class Solution {
public:
    int countSegments(string s) {


        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if( (i == 0 || s[i-1] == ' ') && s[i] != ' '){
                cnt++;
            }
        }
        return cnt;
    }
};

// Why i == 0 needs in the if?
// because it gives the out of index error if we don't put the i == 0?

// Algorithm

// To count the number of segments, it is equivalent to count the number of string indices 
// at which a segment begins. Therefore, by formally defining the characteristics of such an index,
// we can simply iterate over the string and test each index in turn. Such a definition is as 
// follows:
// a string index begins a segment if it is preceded by whitespace (or is the first index) 
// and is not whitespace itself, which can be checked in constant time. Finally, 
// we simply return the number of indices for which the condition is satisfied.
