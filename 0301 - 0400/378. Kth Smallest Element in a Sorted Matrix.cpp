378. Kth Smallest Element in a Sorted Matrix

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/

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
