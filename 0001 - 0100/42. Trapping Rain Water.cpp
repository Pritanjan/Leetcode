// A0 Brute Force - TLE
// Here, we consider each index as a potential peak and calculate the trapped water that can be held at
// that index. The trapped water at each index is the minimum of the maximum heights on the left and
// right minus the height at that index.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;

        int water = 0;
        for(int i=0; i<n; i++) {
            int leftMax = 0, rightMax = 0;
            // Find the maximum height to the left of the current bar
            for(int j=i; j>=0; j--) leftMax = max(leftMax, height[j]);
            // Find the maximum height to the right of the current bar
            for(int j=i; j<n; j++) rightMax = max(rightMax, height[j]);

            // Calculate the trapped water at this position
            water += min(leftMax, rightMax) - height[i];
        }
        return water;
    }
};





// A1 - Using Two Pointers

// It involves using two pointers, one starting from the left and another starting from the right. 
// Now traverse the array while maintaining the maximum height encountered from the left and the
// maximum height encountered from the right. 
// Calculate the amount of water that can be trapped at each index and add it to the total.

class Solution {
public:
    int trap(vector<int>& h) {
        int L = 0, R = h.size()-1;
        int left_max = 0, right_max = 0;
        int water = 0;         
        while(L < R) {
            if(h[L] < h[R]) {
                if(h[L] >= left_max) left_max = h[L];
                else water += left_max - h[L];
                L++;
            }
            else {
                if(h[R] >= right_max) right_max = h[R];
                else water += right_max - h[R];
                R--;
            }
        }
        return water;
    }
};






// A2 - DP

// Here, we precompute the maximum height on the left and right of each index. 
// Then, for each index, calculate the trapped water based on the minimum of the 
// maximum height on the left and right sides.

class Solution {
public:
    int trap(vector<int>& height) { 
        int n = height.size();
        if(n <= 2) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // Precompute maximum heights to the left
        for(int i=1; i<n; i++) leftMax[i] = max(leftMax[i-1], height[i]);
        // Precompute maximum heights to the right
        for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1], height[i]);

        // Calculate trapped water at each position
        int water = 0;
        for(int i=0; i<n; i++) water += min(leftMax[i], rightMax[i]) - height[i];
        return water;
    }
};






// A3 -  Using a Stack

// It uses a stack to keep track of the indices of the bars in a decreasing order of height.
// As we traverse the array, calculate the trapped water by popping elements from the stack and
// updating the trapped water accordingly.

class Solution {
public:        
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        stack<int> st;
        int water = 0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int distance = i - 1 - st.top() ;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};










