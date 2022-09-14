// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// SEE EDITORIAL

APPROACH 1
Explanation
	1. A simple method is to do a row-wise traversal of the matrix, 
	2. count the number of 1s in each row, and compare the count with max.
	3. Finally, return the index of the row with maximum 1s. 
	4. The time complexity of this method is O(m*n) and space complexity O(1)
	 where m is the number of rows and n is the number of columns in the matrix.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	   // vector<int> v;
	    int mx = 0, ans = -1;
	    
	    for(int i=0; i<n; i++){
	        int cnt = 0;
	        for(int j=0; j<m; j++){
	            if(arr[i][j] == 1)
	                cnt++;
	        }
            if(cnt > mx){
                mx = cnt;
                ans = i;
            }
	            
	       // v.push_back(cnt);
	       // for(int i=0; i<v.size(); i++){
	       //     mx = max(mx, v[i]);
	       //     ans = i;
	       // }
	    }
	    // return *max_element(v.begin(), v.end());
	    return ans;
	}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends




APPROACH 2
Explanation
    1. Since each row is sorted, we can use Binary Search to count of 1s in each row.
    2. We find the index of first instance of 1 in each row. 
    3. The count of 1s will be equal to total number of columns minus the index of first 1.

	
// Function to find the index of first instance of 1 in a boolean array arr[] 
int first(bool arr[], int low, int high) 
{ 
    if(high >= low) 
    { 
        // Get the middle index 
        int mid = low + (high - low)/2; 
    
        // Check if the element at middle index is first 1 
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1) 
            return mid; 
    
        // If the element is 0, recur for right side 
        else if (arr[mid] == 0) 
            return first(arr, (mid + 1), high); 
        
        // If element is not first 1, recur for left side 
        else
            return first(arr, low, (mid -1)); 
    } 
    return -1; 
} 

// Function that returns index of row with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) 
{ 
    // Initialize max values 
    int max_row_index = 0, max = -1; 

    // Traverse for each row and count number of 1s 
    // by finding the index of first 1 
    int i, index; 
    for (i = 0; i < R; i++) 
    { 
        index = first (mat[i], 0, C-1); 
        if (index != -1 && C-index > max) 
        { 
            max = C - index; 
            max_row_index = i; 
        } 
    } 

    return max_row_index; 
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
