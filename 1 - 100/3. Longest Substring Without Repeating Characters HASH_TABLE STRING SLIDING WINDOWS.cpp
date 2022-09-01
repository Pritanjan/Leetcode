//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int start = -1;
        int lensub = 0;
        
        for(int i=0; i<s.size(); i++){
            if(v[s[i]] > start)
                start  = v[s[i]];
            v[s[i]] = i;
            
            lensub = max(lensub, i-start);
     
        }
        return lensub;
    }
};
