// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

// APPROACH 1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat) {
        vector<int> v;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                v.push_back(mat[i][j]);
            }
        }
        
        sort(v.begin(), v.end());
        int k = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mat[i][j] = v[k++];
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends


// APPROACH 2 MIN_HEAP PRIORITY_QUEUE

class Solution {
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                pq.push(Mat[i][j]);
                
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Mat[i][j]=pq.top();
                pq.pop();
            }
        }
        return Mat;
    
        
    }
};









