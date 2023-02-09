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









