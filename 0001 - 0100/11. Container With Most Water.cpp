// A 0  ( TLE ) Brute Force

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = min(height[i], height[j]);
                int w = j - i;
                maxWater = max(maxWater, h * w);
            }
        }
        return maxWater;
    }
};

// * **Time Complexity : -**  `O(N^2)` where ‘N’ is the number of elements in the given array/list.
// Since we are pivoting each element once and for each element we are traversing the given array/list till the end. So there will be a total of ‘N’ elements to pivot and then to traverse the given array/list will take O(N) time. Thus, the overall time complexity will be O(N^2).
// * **Space Complexity :-** ` O(1)`
// Since we are not using any extra space and thus the space complexity will be O(1).






// A 1 - 2 Pointer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int L = 0;
        int R = height.size() - 1;
        while(L < R) {
            int h = min(height[L], height[R]);
            int w = R - L;
            // Calculate the area of the current container.
            maxWater = max(maxWater, h * w);
            if(height[L] < height[R]) L++;
            else R--;
        }
        return maxWater;
    }
};

// T.C. - `O(N)`   Since we traverse the sequence once to find the container with maximum water
// S.C. - `O(1)`   We are using constant space.


// OR


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), i = 0, j = n - 1;
        int maxarea = (j - i) * min(height[i], height[j]);        
        while (i < j) {
            if(height[i] < height[j]) i++;
            else j--;
            maxarea = max(maxarea, (j - i) * min(height[i], height[j]));
        }        
        return maxarea;
    }
};





// A 2 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int sum = 0;        
        while(L < R){
            int h = min(height[L], height[R]);
            sum = max(sum, h*(R-L));
            
            while(height[L] <= h && L < R) L++;
            while(height[R] <= h && L < R) R--;
        }
        return sum;
    }
};


