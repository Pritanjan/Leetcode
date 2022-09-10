// See it
// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/


An array contains both positive and negative numbers in random order. Rearrange the array elements so
that all negative numbers appear before all positive numbers.
  
Examples : 
  Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
  Output: -12 -13 -5 -7 -3 -6 11 6 5

// APPROACH 1 (Navie Approach) : - If the order is not important
    
      sort(arr.begin(),arr.end());

    Time Complexity: O(n*log(n)), Where n is the length of the given array.
    Auxiliary Space: O(n)
    
    Output
    -7 -3 -1 2 4 5 6 8 9 
    

// APPROACH 2 ( Efficient Approach )
      

