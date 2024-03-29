// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Kth largest element
// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/1925038/c-solution-using-stl-215-kth-largest-element-in-an-array


// APPROACH 1
//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r - l + 1;
        sort(arr, arr+n);
        return arr[k-1];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends



// APPROACH 2

int kthSmallest(int A[], int l, int r, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        for(int i=l; i<=r; i++){
            pq.push(A[i]);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
