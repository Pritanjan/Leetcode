// https://leetcode.com/problems/container-with-most-water/
// https://leetcode.com/problems/container-with-most-water/discuss/2594527/C%2B%2B-oror-2-Solution-oror-2-Pointer-with-explanation

// https://medium.com/enjoy-algorithm/container-with-most-water-bdbd1a29481c



// APPROACH 1  ( TLE ) Brute Force

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int max_amt = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int area = (j-i) * min(h[i], h[j]);
                max_amt = max(max_amt, area);
            }
        }
        return max_amt;
    }
};

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N^2)` where ‘N’ is the number of elements in the given array/list.
Since we are pivoting each element once and for each element we are traversing the given array/list till the end. So there will be a total of ‘N’ elements to pivot and then to traverse the given array/list will take O(N) time. Thus, the overall time complexity will be O(N^2).
* **Space Complexity :-** ` O(1)`
Since we are not using any extra space and thus the space complexity will be O(1).


// APPROACH 2 - 2 Pointer

class Solution {
public:
    int maxArea(vector<int>& h) {
        // Initialise the two pointers.
        int L = 0;
        int R = h.size() - 1;
        // Variable to store the max_amt possible.
        int max_amt = 0;
        
        while(L < R) {
            // Calculate the area of the current container.
            int area = (R - L) * (min(h[L], h[R]));

            // Update max_amt.
            max_amt = max(max_amt, area);

            // Increment L if h[L] is less than or equal to h[R].
            if (h[L] <= h[R]) {
                L += 1;
            }
            // Otherwise decrement R.
            else {
                R -= 1;
            }
        }
        // Return the maximum area of the container.
        return max_amt;
    }
};

// COMPLEXITY ANALYSIS : -
// Time Complexity : -**  `O(N)`   Since we traverse the sequence once to find the container with maximum water
// Space Complexity :-** ` O(1)`   We are using constant space.


// APPROACH 2 ???
class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int sum = 0;
        
        while(L < R){
            int h = min(height[L], height[R]);
            sum = max(sum, h*(R-L));
            
            while(height[L] <=h && L<R ){
                L++;
            }
            while(height[R] <=h && L<R){
                R--;
            }            
        }
        return sum;
    }
};











