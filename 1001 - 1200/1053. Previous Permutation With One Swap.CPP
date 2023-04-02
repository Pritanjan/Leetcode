// APPROACH 1

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> v;
        int prev1 = -1, prev2 = -1;
        for(int i=0; i<arr.size(); ++i){
            while(v.size() && arr[i] >= arr[v.back()]) v.pop_back();
            v.push_back(i);
            
            if(v.size() > 1) {
                if(v[v.size()-2] > prev1 || (v[v.size()-2] == prev1 && arr[prev2] < arr[i])) {
                    prev1 = v[v.size()-2];
                    prev2 = v.back();
                }
            }
        }
        
        if(prev1 != prev2) swap(arr[prev1], arr[prev2]);
        return arr;
    }
};





// APPROACH 2  [ [3,1,1,3] GIBES WRONG OUTPUT ]

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i, j;
        
        // find the largest index i such that arr[i] > arr[i+1]
        for (i = n-2; i >= 0; i--) {
            if (arr[i] > arr[i+1])
                break;
        }
        
        // if no such index exists, return the array itself
        if (i < 0)
            return arr;
        
        // find the largest index j such that arr[j] < arr[i]
        for (j = n-1; j > i; j--) {
            if (arr[j] < arr[i])
                break;
        }
        
        // swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
        
        return arr;
    }
};


// The idea is to find the largest index i such that arr[i] > arr[i+1]. This means that
// there is a "dip" in the array, i.e., the values are increasing and then suddenly decrease. 
// We need to find a value smaller than arr[i] to swap it with, so that we get a smaller
// permutation. To do this, we find the largest index j such that arr[j] < arr[i], and 
// swap the values arr[i] and arr[j].

// If there is no such index i, then the array is already the lexicographically smallest 
// permutation, and we return the array itself.

// Note that this algorithm modifies the input array arr in place. If you want to keep 
// the input array intact, you can create a copy of the array and work on the copy instead.




// APPROACH 3

// The algorithm is:

// 1. Starting from the second last element of the array, find the rightmost element 4
//    that is smaller than its next element. Let's call this element arr[i].
// 2. Find the rightmost element to the right of arr[i] that is strictly smaller than arr[i].
//    Let's call this element arr[j].
// 3. Swap arr[i] and arr[j].
// 4. Reverse the subarray to the right of i.



class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for(int i=n-2; i>=0; i--) {   // Step 1
            if(arr[i] > arr[i+1]) {   // Step 1 cont.
                int j = n - 1;
                while(arr[j] >= arr[i] || arr[j] == arr[j - 1])  j--;  // Step 2
                swap(arr[i], arr[j]);    // Step 3
                break;
            }
        }
        return arr;
    }
};


// T.C. --> O(N)
// S.C. --> O(1)




// APPROACH 4

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for(int i = n-1; i ; --i){
            if(arr[i-1] > arr[i]){
                swap(arr[i-1], *lower_bound(arr.begin()+i, arr.end(),
                                *prev(lower_bound(arr.begin()+i, arr.end(), arr[i-1]))));
                return arr;
            }
        }
        return arr;
    }
};



