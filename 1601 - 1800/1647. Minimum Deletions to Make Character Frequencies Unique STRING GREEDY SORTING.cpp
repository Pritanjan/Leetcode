// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/submissions/

// Greedy works since we can only delete characters (we cannot add or replace characters).

// So, count each character first. For each 26 characters, check if it's count is already used. If so, delete characters until you find unused count, or reach zero.

class Solution {
public:
    int minDeletions(string s) {
        
        int freq[26] = {};
        int ans = 0;
        
        unordered_set<int> set;
        for(char i : s)
            freq[i - 'a']++;
        
        for(int i=0; i<26; i++){
            for(;freq[i] > 0  && !set.insert(freq[i]).second; freq[i]--) 
                ans++;
            
            // line 14 15 16 or these lines
            
            // while(freq[i] > 0 && map[freq[i]] > 0){
            //     ans++;
            //     map[freq[i]];
            //     freq[i]--;
            // }
            // map[freq[i]] = true;
        }
        return ans;
        
    }
};

//Time: O(n); note that the second loop will not have more than 26 * 26 total operations.
//Memory: O(1) as we will not store more than 26 different frequencies.
