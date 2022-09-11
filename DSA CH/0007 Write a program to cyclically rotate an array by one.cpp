// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1


// APPROACH 1
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++

void rotate(int arr[], int n)
{
    int p = arr[n-1];
    
    for(int i=n; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = p;
}


// n = 5
// i = 4 3 2 1

// p = arr[4] = 5
    
//     i     1  2  3  4  5
// // A[] = {1, 2, 3, 4, 5}

// i = 5,   arr[5] = arr[4] = 4
// i = 4,   arr[4] = arr[3] = 3
// i = 3,   arr[3] = arr[2] = 2
// i = 2,   arr[2] = arr[1] = 1








