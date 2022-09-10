//https://leetcode.com/problems/longest-common-prefix/
//Vertical Scanning

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        if(s.empty())
            return "";
        
        for(int i=0; i<s[0].size(); i++){
            for(int j=1; j<s.size(); j++){
                if(i == s[j].size() || s[0][i] != s[j][i])
                    return s[0].substr(0,i);
            }
        }
        return s[0];
    }
};

//Time complexity : O(S)O(S) , where S is the sum of all characters in all strings. In the worst case there will be nn equal strings with length mm and the algorithm performs S = m \cdot nS=m·n character comparisons. Even though the worst case is still the same as Approach 1, in the best case there are at most n \cdot minLenn·minLen comparisons where minLenminLen is the length of the shortest string in the array.
//Space complexity : O(1)O(1). We only used constant extra space.
