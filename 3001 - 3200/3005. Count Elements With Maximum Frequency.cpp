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






// A 2 - Sort Frequencies and Sum Max Frequencies

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Find the frequency of each element
        vector<int> freq(100, 0);
        for(auto num : nums) freq[num - 1]++;

        // Determine the maximum frequency, stored in the last index of the sorted array
        sort(freq.begin(), freq.end());
        int mxFreqIdx = freq.size() - 1;
        int totalFreq = freq[mxFreqIdx];

        // Calculate the total frequencies of elements with the maximum frequency
        // Start from the last index and iterate right to left
        while (mxFreqIdx > 0 && freq[mxFreqIdx] == freq[mxFreqIdx - 1]) {
            totalFreq += freq[mxFreqIdx];
            mxFreqIdx--;
        }
        return totalFreq;
    }
};






// A 3 

