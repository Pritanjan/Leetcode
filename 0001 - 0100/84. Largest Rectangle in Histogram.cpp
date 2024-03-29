// A 0 - Brute Force  TLE
// It involves checking every possible rectangle starting from each bar in the histogram and
// calculating its area

class Solution {
public:      
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;        
        for (int i = 0; i < n; i++) {
            int minHeight = heights[i];
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                int width = j - i + 1;
                int area = minHeight * width;
                maxArea = max(maxArea, area);
            }
        }        
        return maxArea;
    }  
};






// A 1

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> res(n);
        for(auto i=n-1; i>=0; i--) {
            int cur = arr[i];        
            while(stk.top() != -1 && arr[stk.top()] >= cur) stk.pop();
            res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> res(n);
        for(auto i=0; i<n; i++){
            int cur = arr[i];
            while(stk.top() != -1 && arr[stk.top()] >= cur) stk.pop();
            res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> next(n), prev(n)
        next = nextSmallerElement(h, n);
        prev = prevSmallerElement(h, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int L = h[i];
            // when all element is equal 
            if(next[i] == -1) next[i] = n;
            int B = next[i] - prev[i] - 1;
            int newArea = L * B;
            area = max(area, newArea);
        }
        return area;
    }
};

// T.C. O(N)
// S.C. O(N)






// A 2
// 1. Create an empty stack.
// 2. Start from the first bar, and do the following for every bar h[i] where ‘i‘ varies from 0 to n-1
//    A. If the stack is empty or h[i] is higher than the bar at top of the stack,
//       then push ‘i‘ to stack. 
//    B. If this bar is smaller than the top of the stack, then keep removing the top of the stack
//       while the top of the stack is greater. 
//    C. Let the removed bar be h[tp]. Calculate the area of the rectangle with h[tp] as the smallest bar.
//    D. For h[tp], the ‘left index’ is previous (previous to tp) item in stack and
//       ‘right index’ is ‘i‘ (current index).
// 3. If the stack is not empty, then one by one remove all bars from the stack and
//    do step (2.2 and 2.3) for every removed bar

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        // Create an empty stack. The stack holds indexes of hist[] array. 
        // The bars stored in stack are always in increasing order of their heights.
        stack<int> stk;
        int max_area = 0;       // Initialize max area
        int tp;                 // To store top of stack
        int area_with_top;      // To store area with top bar as the smallest bar
  
        // Run through all bars of given histogram
        int i = 0;
        while(i < n) {
            // If this bar is higher than the bar on top stack, push it to stack
            if (stk.empty() || h[stk.top()] <= h[i]) stk.push(i++);
  
            // If this bar is lower than top of stack, then calculate area of rectangle with stack
            // top as the smallest (or minimum height) bar.
            // 'i' is 'right index' for the top and element before top in stack is 'left index'
            else {
                tp = stk.top();   // store the top index
                stk.pop();        // pop the top
  
                // Calculate the area with hist[tp] stack as smallest bar
                area_with_top = h[tp] * (stk.empty() ? i : i - stk.top() - 1);
  
                // update max area, if needed
                if(max_area < area_with_top) max_area = area_with_top;
            }
        }
        
        // Now pop the rem bars from stack & calculate area with every popped bar as the smallest bar
        while(stk.empty() == false) {
            tp = stk.top();
            stk.pop();
            area_with_top = h[tp] * (stk.empty() ? i : i - stk.top() - 1);
  
            if (max_area < area_with_top) max_area = area_with_top;
        }
        return max_area;
    }
};


// OR


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;
        
        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }
        return maxArea;
    }      
};

// T.C. : O(N), Since every bar is pushed and popped only once
// S.C. : O(N)






// A 3

class Solution {
public:      
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        
        for(int i=0; i<n; i++) {
            while(!s1.empty() && heights[i] <= heights[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && heights[i] <= heights[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }        
        return maxArea;
    }
};


// OR


// Largest Rectangular Area in a Histogram by finding the next and the previous smaller element:

// Find the previous and the next smaller element for every element of the histogram,
// as this would help to calculate the length of the subarray in which this current
// element is the minimum element. So we can create a rectangle of size 
// (current element * length of the subarray) using this element. Take the maximum of
// all such rectangles.

// Follow the given steps to solve the problem:
// 1. First, we will take two arrays leftSmall[] and rightSmall[] and initialize them with -1 & n.
// 2. For every element, we will store the index of the previous smaller and next smaller element in 
//    leftSmall[] and rightSmall[] arrays respectively
// 3. Now for every element, we will calculate the area by taking this ith element as the smallest in
//    the range leftSmall[i] and rightSmall[i] and multiplying it with the difference of leftSmall[i] 
//    and rightSmall[i]
// 4. We can find the maximum of all the areas calculated in step 3 to get the desired maximum area

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk; stk.push(-1);
        vector<int> leftSmall(n, -1), rightSmall(n, n);

        int area = arr[0];
        int idx = 0;
        while(idx < n) {
            while(!stk.empty() && stk.top() != -1 && arr[stk.top()] > arr[idx]) {
                rightSmall[stk.top()] = idx;
                stk.pop();
            }
            if(idx > 0 && arr[idx] == arr[idx - 1]) leftSmall[idx] = leftSmall[idx - 1];            
            else leftSmall[idx] = stk.top();
            
            stk.push(idx);
            idx++;
        }
        for(int j=0; j<n; j++) {
            area = max(area, arr[j] * (rightSmall[j] - leftSmall[j] - 1));
        }
        return area;
    }
};






// A 4 - Recursion  TLE 
// It divides the problem into smaller subproblems and recursively finds the maximum area. 
// It then combines the results to get the maximum area of the entire histogram.

class Solution {
public:
    int recursion(vector<int>& heights, int L, int R) {
        if(L > R) return 0;
        int miIdx = L;
        for(int i=L; i<=R; i++) {
            if(heights[i] < heights[miIdx]) miIdx = i;
        }
        
        int area = heights[miIdx] * (R - L + 1);
        int leftArea = recursion(heights, L, miIdx - 1);
        int rightArea = recursion(heights, miIdx + 1, R);
        return max(area, max(leftArea, rightArea));
    }

    int largestRectangleArea(vector<int>& heights) {
        return recursion(heights, 0, heights.size() - 1);
    }
};





// A 5
