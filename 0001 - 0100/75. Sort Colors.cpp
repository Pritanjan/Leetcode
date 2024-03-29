// A 1    
// DUTCH NATIONAL FLAG (DNF)

// This programming problem was proposed by Edsger Dijkstra. The flag of the Netherlands consists 
// of three colors: white, red, and blue. The task is to randomly arrange balls of red, white, and 
// blue in such a way that balls of the same color are placed together. For DNF (Dutch National Flag),
// we sort an array of 0, 1, and 2's in linear time that does not consume any extra space. We have 
// to keep in mind that this algorithm can be implemented only on an array that has three unique 
// elements.

// ALGORITHM : -
// Take three-pointers, namely - L , mid , high.
// We use L and mid pointers at the start, and the R pointer will point at the end of the given array.

// CASES : -
// If array [mid] =0 , then swap array [mid] with array [L] and increment both pointers once.
// If array [mid] = 1 , then no swapping is required. Increment mid pointer once.
// If array [mid] = 2 , then we swap array [mid] with array [R] and decrement the high pointer once.

// Binary Search
    
class Solution {
public:
    void sortColors(vector<int>& a) {
        int L = 0;
        int R = a.size() - 1;
        int mid = 0;
        
        while (mid <= R){
            switch(a[mid]){
                case 0 :{
                    swap(a[L++], a[mid++]);
                    break;
                }
                case 1 : {
                    mid++;
                    break;
                }
                case 2 : {
                    swap(a[mid], a[R--]);
                    break;
                }
            }
        }
    }
};


// OR
// Counting Sort (Dutch National Flag Algorithm):


class Solution {
public:        
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        int n = nums.size();
        
        for(int i=0; i<n; i++) cnt[nums[i]]++;
        
        int idx = 0;
        for(int color=0; color<3; color++) {
            for(int j=0; j<cnt[color]; j++) {
                nums[idx++] = color;
            }
        }
    }
};






// A 2

class Solution {
public:
    void sortColors(vector<int>& a) {
        int L = 0;
        int n = a.size();
        int R = n-1;
        int mid = 0;        
        while(mid <= R ){
            if(a[mid] == 0) swap(a[L++], a[mid++]);
            else if(a[mid] == 1)mid++;
            else swap(a[mid], a[R--]);
        }
    }
}; 





// A 3

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int i;
        int j;
        int t;
        for(i = 0 ; i < len -1;i++)
            for(j = 0;j< len -1;j++) {
                if(nums[j]>nums[j+1]) {
                    t = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = t;
                }
            }
    }
};






// A 4

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        
        for(auto i : nums){
            if(i == 0) zero++;
            if(i == 1) one++;
            if(i == 2) two++;
        }
                
        int i = 0;
        while(zero--) nums[i++] = 0;
        while(one--) nums[i++] = 1;
        while(two--) nums[i++] = 2;
    }
};






// A 5 - Counting Sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();   
        for(int i=0; i<n-1; i++) {
            int minIdx = i;
            for(int j=i+1; j<n; j++) {
                if(nums[j] < nums[minIdx]) minIdx = j;
            }
            swap(nums[i], nums[minIdx]);
        }
    }
};






// A 6  -  Bubble Sort:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        
        for(int i=0; i<n-1; i++) {
            swapped = false;
            for(int j=0; j<n-i-1; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            // If no swaps were made in an iteration, the array is already sorted.
            if(!swapped) break; 
        }
    }          
};






// A 7 Merge Sort 
// Implement a variation of the merge sort algorithm to sort the colors. 
// This approach creates 3 separate arrays for each color and 
// then merges them back into the original array:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> R, W, B;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) R.push_back(nums[i]);
            else if(nums[i] == 1) W.push_back(nums[i]);
            else B.push_back(nums[i]);
        }
        
        int idx = 0;
        for(int num : R) nums[idx++] = num;
        for(int num : W) nums[idx++] = num;
        for(int num : B) nums[idx++] = num;
    }
};






// A 8 - Radix Sort:
// Radix sort is another sorting algorithm that can be used to sort the colors. 
// Since there are only three distinct colors (0, 1, and 2), 
// we can apply radix sort to sort the colors in linear time:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // Counting sort for the least significant digit (0s).
        vector<int> count(3, 0);
        vector<int> output(n);
        
        for(int i=0; i<n; i++) count[nums[i]]++;        
        for(int i=1; i<3; i++) count[i] += count[i-1];  
        for(int i=n-1; i>=0; i--) {
            output[count[nums[i]] - 1] = nums[i];
            count[nums[i]]--;
        }
        
        // Copy sorted output to the original array.
        for(int i=0; i<n; i++) {
            nums[i] = output[i];
        }
    }
};

