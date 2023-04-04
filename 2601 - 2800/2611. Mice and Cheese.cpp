class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int K) {
        int n = reward1.size();
        
        // Initially assume it was eaten by the second mouse
        long long ans = 0;
        for(int x : reward2) ans += x;

        // Calculate the change in score for each cheese
        vector<int> vec;
        for (int i = 0; i < n; i++) vec.push_back(reward1[i] - reward2[i]);
        sort(vec.begin(), vec.end());

        // Select the top K largest score change
        for (int i = 1; i <= K; i++) ans += vec[n - i];
        return ans;
    }
};

