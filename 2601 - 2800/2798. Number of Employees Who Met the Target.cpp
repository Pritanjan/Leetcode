// APPROACH 1 LINEAR SEARCH

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = hours.size();
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            if(hours[i] >= target) cnt++;
        }
        return cnt;
    }
};



// APPROACH 2 STL

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res = count_if(hours.begin(), hours.end(), [&](int h) { return h >= target; });
        return res;
    }
};





// APPROACH 3 DIVDE & CONQUER

class Solution {
public:
    int f(vector<int>& hours, int target, int L, int R) {
        if(L >= R) return 0;
        int mid = L + (R-L) / 2;
        int Lcnt = f(hours, target, L, mid);    // Change here: Use mid as the right boundary for left subarray.
        int Rcnt = f(hours, target, mid+1, R);  // Change here: Use mid + 1 as the left boundary for right subarray.

        return Lcnt + Rcnt + (hours[mid] >= target ? 1 : 0);
    }
    
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return f(hours, target, 0, hours.size());
    }
};




// APPROACH 4  PRIORITY QUEUE

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto h : hours) minHeap.push(h);

        int cnt = 0;
        while(!minHeap.empty() && minHeap.top() < target) {
            minHeap.pop();
            cnt++;
        }
        return hours.size() - cnt;
    }
};



