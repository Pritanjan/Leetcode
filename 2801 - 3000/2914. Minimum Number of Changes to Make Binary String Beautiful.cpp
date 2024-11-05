// A 1

class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        // Iterate over the string in pairs
        for (int i = 0; i < s.length(); i += 2) {
            // Check if current pair (s[i], s[i+1]) is mismatched
            if (s[i] != s[i + 1]) {
                changes++; // Increment change count for each mismatched pair
            }
        }
        return changes;
    }
};
