//https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L1 = 0;
        int L2 = 0;
        string ans;
        
        while((L1 < word1.size()) || (L2 < word2.size())  ){
            if(L1 < word1.size()){
                ans += word1[L1++];
                // L1++;
            }
            if(L2 < word2.size()){
                ans += word2[L2++];
                // L2++;
            }
        }
        return ans  ;
    }
};


//T.C. --> O(s1.size() + s2.size() )
//S.C. --> O(1)
