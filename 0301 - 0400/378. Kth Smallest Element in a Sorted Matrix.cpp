// QUESTION 
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

// SOLUTION 
// https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/


// A 1 - Using MAX_HEAP priority_queue 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // vector<int> v(n);
        priority_queue<int> pq;        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};


// OR
// Using MIN_HEAP priority_queue 


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                pq.push(matrix[i][j]);                
            }
        }
        while(--k) pq.pop();
        return pq.top();
    }
};


// OR


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i<n; ++i) {
            pq.push({matrix[i][0], {i, 0}});
        }

        while(--k) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first, j = top.second.second;
            if(j + 1 < n)
                pq.push({matrix[i][j + 1], {i, j + 1}});
        }
        return pq.top().first;
    }
};






// A 2  - Using a temp array

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v;
        for(int i=0; i<n; i++)  {
            for(int j=0; j<n; j++){
                v.push_back(matrix[i][j]);
            }
        }   
        sort(v.begin(), v.end());
        return v[k-1];
    
        // 16 28 60 64 22 41 63 91 27 50 87 93 36 78 87 94
        // 16 22 27 28 36 41 50 60 63 64 78 87 87 91 93 94
    }
};


// OR


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v;
        for(int i=0; i<n; ++i) {
            v.insert(v.end(), matrix[i].begin(), matrix[i].end());
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};






// A 3 - Binary Search 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0];
        int R = matrix[n-1][n-1];
        while(L < R) {
            int mid = L + (R - L) / 2;
            int cnt = 0;
            for(int i=0; i<n; ++i)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(cnt < k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};






// A 4

