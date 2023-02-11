// APPROACH 1

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> res(n);

        for(auto i=n-1; i>=0; i--){
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
        vector<int> next(n);
        next = nextSmallerElement(h, n);

        vector<int> prev(n);
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







// APPROACH 2

// 1. Create an empty stack.

// 2. Start from the first bar, and do the following for every bar h[i] 
//    where ‘i‘ varies from 0 to n-1
//    A. If the stack is empty or h[i] is higher than the bar at top of the stack,
//       then push ‘i‘ to stack. 
//    B. If this bar is smaller than the top of the stack, then keep removing the
//       top of the stack while the top of the stack is greater. 
//    C. Let the removed bar be h[tp]. Calculate the area of the rectangle with 
//       h[tp] as the smallest bar. 
//    D. For h[tp], the ‘left index’ is previous (previous to tp) item in stack and
//       ‘right index’ is ‘i‘ (current index).

// 3. If the stack is not empty, then one by one remove all bars from the stack and
//    do step (2.2 and 2.3) for every removed bar


class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        // Create an empty stack. The stack holds indexes
        // of hist[] array. The bars stored in stack are
        // always in increasing order of their heights.
        stack<int> stk;
    
        int max_area = 0; // Initialize max area
        int tp; // To store top of stack
        int area_with_top; // To store area with top bar as the smallest bar
  
        // Run through all bars of given histogram
    
        int i = 0;
        while (i < n) {
            // If this bar is higher than the bar on top
            // stack, push it to stack
            if (stk.empty() || h[stk.top()] <= h[i]) stk.push(i++);
  
            // If this bar is lower than top of stack,
            // then calculate area of rectangle with stack
            // top as the smallest (or minimum height) bar.
            // 'i' is 'right index' for the top and element
            // before top in stack is 'left index'
            else {
                tp = stk.top(); // store the top index
                stk.pop(); // pop the top
  
                // Calculate the area with hist[tp] stack
                // as smallest bar
                area_with_top = h[tp] * (stk.empty() ? i : i - stk.top() - 1);
  
                // update max area, if needed
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
  
        // Now pop the remaining bars from stack and calculate
        // area with every popped bar as the smallest bar
        while (stk.empty() == false) {
            tp = stk.top();
            stk.pop();
            area_with_top = h[tp] * (stk.empty() ? i : i - stk.top() - 1);
  
            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }
};

// Time Complexity: O(N), Since every bar is pushed and popped only once
// Auxiliary Space: O(N)





// APPROACH 1

// Time Complexity: O(N)
// Auxiliary Space: O(N)

// Largest Rectangular Area in a Histogram by finding the next and the previous smaller element:

// Find the previous and the next smaller element for every element of the histogram,
// as this would help to calculate the length of the subarray in which this current
// element is the minimum element. So we can create a rectangle of size 
// (current element * length of the subarray) using this element. Take the maximum of
// all such rectangles.

// Follow the given steps to solve the problem:

// 1. First, we will take two arrays left_smaller[] and right_smaller[] and initialize 
//    them with -1 and n respectively

// 2. For every element, we will store the index of the previous smaller and next smaller 
//    element in left_smaller[] and right_smaller[] arrays respectively

// 3. Now for every element, we will calculate the area by taking this ith element as the 
//    smallest in the range left_smaller[i] and right_smaller[i] and multiplying it with 
//    the difference of left_smaller[i] and right_smaller[i]

// 4. We can find the maximum of all the areas calculated in step 3 to get the desired 
//    maximum area


int getMaxArea(int arr[], int n)
{
    // Your code here
    // we create an empty stack here.
    stack<int> s;
    // we push -1 to the stack because for some elements
    // there will be no previous smaller element in the
    // array and we can store -1 as the index for previous
    // smaller.
    s.push(-1);
    int area = arr[0];
    int i = 0;
    // We declare left_smaller and right_smaller array of
    // size n and initialize them with -1 and n as their
    // default value. left_smaller[i] will store the index
    // of previous smaller element for ith element of the
    // array. right_smaller[i] will store the index of next
    // smaller element for ith element of the array.
    vector<int> left_smaller(n, -1), right_smaller(n, n);
    while (i < n) {
        while (!s.empty() && s.top() != -1
               && arr[s.top()] > arr[i]) {
            // if the current element is smaller than
            // element with index stored on the top of stack
            // then, we pop the top element and store the
            // current element index as the right_smaller
            // for the popped element.
            right_smaller[s.top()] = i;
            s.pop();
        }
        if (i > 0 && arr[i] == arr[i - 1]) {
            // we use this condition to avoid the
            // unnecessary loop to find the left_smaller.
            // since the previous element is same as current
            // element, the left_smaller will always be the
            // same for both.
            left_smaller[i] = left_smaller[i - 1];
        }
        else {
            // Element with the index stored on the top of
            // the stack is always smaller than the current
            // element. Therefore the left_smaller[i] will
            // always be s.top().
            left_smaller[i] = s.top();
        }
        s.push(i);
        i++;
    }
    for (int j = 0; j < n; j++) {
        // here we find area with every element as the
        // smallest element in their range and compare it
        // with the previous area.
        // in this way we get our max Area form this.
        area = max(area, arr[j]
                             * (right_smaller[j]
                                - left_smaller[j] - 1));
    }
    return area;
}
