// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> v;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                v.push_back(matrix[i][j]);
            }
        }
        // sort(v, v+(r*c));
        sort(v.begin(), v.end());
        return v[v.size()/2];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends



