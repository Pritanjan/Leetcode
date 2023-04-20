/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */




// APPROACH 1 [ BRUTE FORCE -  TLE ]


class Solution {
public:
    int guessNumber(int n) {
        for(int i=1; i<n; i++){
            if(guess(i) == 0)
                return i;
        }
        return n;
    }
};



// Time complexity  : O(n). We scan all the numbers from 1 to n.
// Space complexity : O(1). No extra space is used.









// APPROACH 2 [ BINARY SEARCH - using only 1 mid] 


class Solution {
public:
    int guessNumber(int n) {
        int L = 1;
        int R = n;
        
        while(1) {
            // int mid = (L+R)/2;
            int mid = L + (R-L)/2;
            int ans = guess(mid);
            
            if(ans == 0) return mid;
            else if(ans == 1) L = mid + 1;
            else R = mid - 1;
        }
        return -1;
    }
};


// Time complexity  : O(log N) base 2  Binary Search is used.
// Space complexity : O(1). No extra space is used.








// APPROACH 3 [ BINARY SEARCH - using 2 mid ]


class Solution {
public:
    int guessNumber(int n) {
        int L = 1;
        int R = n;
        
        while(L <= R){
            // int mid = (L+R)/2;
            int mid1 = R + (R-L)/3;
            int mid2 = R - (R-L)/3;
            int ans1 = guess(mid1);
            int ans2 = guess(mid2);
            
            if(ans1 == 0) return mid1;
            else if(ans2 == 0) return mid2;
            else if(ans1 < 0)  R = mid1 - 1;
            else if(ans2 > 0)  L = mid2 + 1;
            else { 
                L = mid1 + 1;
                R = mid2 - 1;
            }
        }
        return -1;
    }
};

// Time complexity : O(log N) base 3  Binary Search is used.
// Space complexity : O(1). No extra space is used.







