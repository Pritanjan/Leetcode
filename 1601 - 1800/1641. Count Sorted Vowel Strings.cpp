// APPROACH 1

class Solution {
public:
    int countVowelStrings(int n) {
        // Initialize the first row of the dp table
        vector<int> dp(5, 1);
        
        // Fill in the rest of the dp table
        for (int i = 2; i <= n; i++) {
            for (int j = 3; j >= 0; j--) {
                dp[j] += dp[j+1];
            }
        }
        
        // Return the sum of the dp table
        return accumulate(dp.begin(), dp.end(), 0);
    }
};



// Let dp[i][j] be the number of strings of length i that end with the vowel j. 
// Then, we can compute dp[i][j] as the sum of all dp[i-1][k] for k >= j. 
// Becs we can append any vowel that comes after j to a string of length i-1 that ends with j.

// Since we only care about the number of strings of length n, the SC can be reduce by using 
// a 1D dp table dp[j] to store the number of strings of length i that end with the vowel j. We can initialize the first row of the dp table as all ones, since there is only one string of length 1 that ends with each vowel.

// Then, we can fill in the rest of the dp table using the recurrence relation dp[j] = dp[j] + dp[j+1]. This is because the number of strings of length i that end with the vowel j is equal to the number of strings of length i-1 that end with the vowel j plus the number of strings of length i-1 that end with any vowel that comes after j.

// Finally, we can return the sum of the dp table, which is the total number of strings of length n that consist only of vowels and are lexicographically sorted.




class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 3, vector<int>(5));
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[1][3] = 1;
        dp[1][4] = 1;
        for(int i = 2; i <= n + 1; i ++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][2] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][3] = dp[i - 1][3] + dp[i - 1][4];
            dp[i][4] = dp[i - 1][4];
        }
        return dp[n + 1][0];
    }
};

