// APPROACH 1

// When we encounter nums[i] = val, we can swap the current element out with the last element and 
// dispose the last one. This essentially reduces the array's size by 1.
// Note that the last element that was swapped in could be the value you want to remove itself. 
// But don't worry, in the next iteration we will still check this element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return n;
    }
};

// T.C. --> O(N). Both i and n traverse at most n steps.
// In this approach, the number of assignment operations is equal to the no of elements to remove.
// So it is more efficient if elements to remove are rare.
// S.C. --> O(1).






// APPROACH 2  Two Pointers

// INTITUTION

// Since this question is asking us to remove all elements of the given value in-place, 
// we have to handle it with O(1) extra space. 
// We will take two pointers l and i, where l is the slow-runner while i is the fast-runner.


// APLGORITHM

// When nums[i] equals to the given value, skip this element by incrementing i.
// As long as nums[i] != val, we copy nums[i] to nums[l] and increment both indexes at the same time. 
// Repeat this process until i reaches the end of the array and the new length is l

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        
        // traverse the array
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){ //Array element nums[i] is different from val
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};

// T.C. --> O(N). Both i and n traverse at most n steps.
// Assume the array has a total of n elements, both l and i traverse at most 2n steps.

// S.C. --> O(1).







// APPROACH 3

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};






