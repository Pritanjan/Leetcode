// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long int arr1[], long long int arr2[], int n, int m) {
        int i = 0;
        int j = 0;
        int k= n-1;
        while (i <= k && j < m) {
            if (arr1[i] < arr2[j])
            {
                i++;
            }
            else
            {
                swap(arr2[j], arr1[k]);
                j++;
                k--;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends

