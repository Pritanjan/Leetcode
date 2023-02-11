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









