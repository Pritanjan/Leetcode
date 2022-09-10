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
