// A 1

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int mask = 0; 
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            // Toggle the bit for 'a'
            if (ch == 'a') mask ^= (1 << 0); 
            // Toggle the bit for 'e'
            else if (ch == 'e') mask ^= (1 << 1); 
            // Toggle the bit for 'e'
            else if (ch == 'i') mask ^= (1 << 2);
            // Toggle the bit for 'i'
            else if (ch == 'o') mask ^= (1 << 3); 
            // Toggle the bit for 'u'
            else if (ch == 'u') mask ^= (1 << 4); 
            
            // If the current mask has been seen before, calculate the substring length
            if (mp.find(mask) != mp.end()) max_len = max(max_len, i - mp[mask]);
            // Otherwise, store the first occurrence of this mask
            else mp[mask] = i;
        }
        return max_len;
    }
};
