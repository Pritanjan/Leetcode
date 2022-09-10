//https://leetcode.com/problems/maximum-product-of-word-lengths/
// USING BITMASK

class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        int ans = 0;
        vector<int> mask(n);
        
        for(int i=0; i<n; i++){
            for(auto& ch : words[i])
                mask[i] |= 1 << (ch - 'a'); // hash the word
            
            for(auto j=0; j<i; j++)
                if((mask[i] & mask[j]) == 0) // no common set bit in the hash of words[i] and words[j]
                    ans = max(ans, int(words[i].size() * words[j].size()) );
        }
        return ans;        
    }
};

//Time Complexity : O(n*(N+n)), though the time complexity remains the same, we save the time needed in solution - I to iterate over hashmap although its only a constant factor (O(26)).
//Space Complexity : O(n)
