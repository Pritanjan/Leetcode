//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1


// APPROACH 1 using MAX_HEAP priority_queue 

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


// APPROACH 2 by using a temp array

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




