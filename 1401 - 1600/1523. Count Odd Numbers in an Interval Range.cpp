// APPROACH 1

//the count of odd numbers between 1 and low - 1 is low / 2
//the count of odd numbers between 1 and high is (high + 1 ) / 2
//
//
//Complexity
//Time O(1)
//Space O(1)

class Solution {
public:
    int countOdds(int L, int R) {
        return (R+1)/2 - L/2;
    }
};




// APPROACH 2

class Solution {
public:
    int countOdds(int L, int R) {
        int ans = (R-L)/2;
        if(L%2!=0 || R%2!=0)
            ans++;
        
        return ans;
        
    }
};







// APPROACH 3


class Solution {
    public int countOdds(int low, int high) {
        int cnt = 0;
        if(low % 2 == 0) low++;
        for(int i = low; i <= high; i = i + 2) cnt++;
        return cnt;
    }
}



// APPROACH 4

class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (!(low & 1)) {
            low++;
        }
  
        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};

// Algorithm

// 1. Check if low is odd. This could be easily checked using % operator, but we used 
//    bit wise operator & as they are more efficient.
// 2. If low is odd, increment it.
// 3. Return (high - low) / 2 + 1. The important point here is to check that if low after
//    incrementing became greater than high this will happen when low = high, and in that
//    case, we should return 0.

// Time complexity: O(1)
// We are using bit-wise and other arithmetic or relational operator that all cost us O(1) time. Hence the time complexity would be constant.

// Space complexity: O(1)
// No extra variable or space is needed, and hence the space complexity would be constant.






