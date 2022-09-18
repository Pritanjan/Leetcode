// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/


class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        int curr = 1;
        for(int i =1;i<s.size();i++){
            if(s[i-1]+1==s[i])
                curr++;
            else{
                ans = max(curr,ans);
                curr=1;
            }
        }
        ans = max(curr,ans);
       return ans;
 
    }
};
