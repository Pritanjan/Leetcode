// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort

1st max-heap priority queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end() );
        for(int i=0; i<k-1; i++){
                pq.pop();
        }
        return pq.top();
    }
};

// We may also use a heap to solve this problem. We can maintain the largest k elements in a heap with the smallest among them at the top. Or we can add all the elements to a heap, with the largest at the top, and then pop the heap for k - 1 times, then the one on the top is our target. The first one is min-heap and the second one is max-heap. In STL, both priority_queue and multiset can be used as a min/max-heap.


2nd MIN-heap priortiy queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums){
            pq.push(i);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};


3rd
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k-1];
    }
};


4th
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {    
        partial_sort(nums.begin(), nums.begin() + k , nums.end(), greater<int>());
        return nums[k-1];
   
    }
};








// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int p[], int l, int r, int k) {
        priority_queue<int> pq;
        
        // step 1 
        for(int i=0; i<k; i++) pq.push(p[i]);
        
        // step 2
        for(int i=k; i<=r; i++){
            if(p[i] < pq.top()){
                pq.pop();
                pq.push(p[i]);
            }
        }
        
        int res = pq.top();
        return res;
    }
};



