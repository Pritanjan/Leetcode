// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1


// APPROACH 1

// Explanation
//     Following are steps.
//     1) Store last element in a variable say x.
//     2) Shift all elements one position ahead.
//     3) Replace first element of array with x.
    
    
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

// Time Complexity: O(n), as we need to iterate through all the elements. 
// Where n is the number of elements in the array.
// Auxiliary Space: O(1), as we are using constant space.



// APPROACH 2

void rotate(int arr[], int n)
{
    for(int i = n-1;i>0;i--){
//         swap(arr[i],arr[n-1]);
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}


// APPROACH 3

void rotate(int arr[], int n)
{
   reverse(arr,arr+n);
   reverse(arr+1,arr+n);
}

// APPROACH 4

void reverse(int arr[],int s,int e){
    while(s<=e){
        swap(arr[s++],arr[e--]);
    }
}

void rotate(int arr[], int n)
{
   reverse(arr,0,n-2);
   reverse(arr,0,n-1);
}


// APPROACH 5
// We can use two pointers, say i and j which point to first and last element of array respectively.
// As we know in cyclic rotation we will bring last element to first and shift rest in forward 
// direction, so start swaping arr[i] and arr[j] and keep j fixed and i moving towards j.  
// Repeat till i is not equal to j.

void rotate(int arr[], int n)
{
    int i = 0, j = n-1; // i and j pointing to first and last element respectively
      while(i != j){
      swap(arr[i], arr[j]);
      i++;
    }
}

// Time Complexity: O(n), as we need to iterate through all the elements. 
// Where n is the number of elements in the array.
// Auxiliary Space: O(1), as we are using constant space.






