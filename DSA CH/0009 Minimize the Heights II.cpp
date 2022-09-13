// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int dif = arr[n-1] - arr[0];
        int mi,mx;
        
        for(int i=0; i<n-1; i++){
            mi = min(arr[0]+k ,arr[i+1]-k);
            mx = max(arr[n-1]-k ,arr[i]+k);
            
            if(mi<0)
                continue;
            else
                dif = min(dif, mx - mi);
        }
        return dif;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


