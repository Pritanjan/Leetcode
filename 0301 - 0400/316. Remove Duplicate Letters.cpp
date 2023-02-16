class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> count(128);
        vector<bool> used(128);

        // Count the frequency of each character in the string
        for(const char c : s) ++count[c];

        // Iterate over the string and remove duplicate characters
        for(const char c : s) {
            --count[c];
            
            if (used[c]) continue;

            while (!ans.empty() && ans.back() > c && count[ans.back()] > 0) {
                used[ans.back()] = false;
                ans.pop_back();
            }
            
            used[c] = true;
            ans.push_back(c);
        }

        return ans;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)



