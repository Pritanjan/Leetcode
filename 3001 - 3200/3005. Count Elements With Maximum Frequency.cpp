// A 1 - Count Frequency and Max Frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> ump;
        
        // Count the frequency of each element
        for(auto i : nums) ump[i]++;
        
        int mx1 = 0;
        // Find the maximum frequency
        for (auto& pair : ump) {
            mx1 = max(mx1, pair.second);
        }
        
        int mx2 = 0;
        // Count how many elements have the maximum frequency
        for (auto& pair : ump) {
            if (pair.second == mx1) mx2++;
        }        
        return mx1 * mx2;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)






// A 2 - 

