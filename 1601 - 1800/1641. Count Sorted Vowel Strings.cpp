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

// Since we only care about the number of strings of length n, therefor SC can be reduce by using 
// a 1D dp table dp[j] to store the number of strings of length i that end with the vowel j.
// We can initialize the first row of the dp table as all ones, 
// since there is only one string of length 1 that ends with each vowel.

// Then, we can fill in the rest of the dp table using the recurrence relation 
// dp[j] = dp[j] + dp[j+1]. 
// as no of strings of length i that end with the vowel j == no. of strings of length i-1 
// that end with the vowel j + the number of strings of length i-1 that end with any
// vowel that comes after j.




// APPROACH 2


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







// APPROACH 3  -- > [copied]

/**
 * When n is increased by one length, for all existing combinations result:
 * Anything that starts with a e i o u can start with a again
 * Anything that starts with e i o u can start with e
 *  …
 */

class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for(int k = 1; k < n ; k++){
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;
        }
        return a + e + i + o + u;
    }
};



/**
 * The permutation and combination algorithm in the solution area is excellent.
 * For an answer of length n required by the title:
 *【If the number of a e i o u is determined, the sorting method is unique】
 * In this way, the problem is transformed into, a string of length n is divided into 5 segments, how many types can be divided
 * Since each element may be 0, each division position can be outside n
 * C(n+4, 4)
 */






// APPROACH 4 [ SINCE N IS SMLL]

class Solution {
    public int countVowelStrings(int n) {
        int[] nums={5, 15, 35, 70, 126, 210, 330, 495, 715, 1001, 1365, 1820, 2380, 3060, 3876, 4845, 5985, 7315, 8855, 10626, 12650, 14950, 17550, 20475, 23751, 27405, 31465, 35960, 40920, 46376, 52360, 58905, 66045, 73815, 82251, 91390, 101270, 111930, 123410, 135751, 148995, 163185, 178365, 194580, 211876, 230300, 249900, 270725, 292825, 316251};
        return nums[n-1];
    }
}







// APPROACH 5

class Solution {
public:
    int res;
    void backtracking(int num, int start) {
        if (num == 0) {
            res++;
            return;
        }
        for (int i = start; i < 5; i++) {
            backtracking(num - 1, i);
        }
    }
    int countVowelStrings(int n) {
        res = 0;
        backtracking(n, 0);
        return res;
    }
};





// APPROACH 6

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> starts = {1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++) {
            for (int j = 3; j >= 0; j--) {
                starts[j] += starts[j+1];
            }
        }
        return accumulate(starts.begin(), starts.end(), 0);
    }
};






