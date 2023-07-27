// APPROACH 1 max-heap priority queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end() );
        for(int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }
};


// We may also use a heap to solve this problem. We can maintain the largest k elements in a
// heap with the smallest among them at the top. Or we can add all the elements to a heap, 
// with the largest at the top, and then pop the heap for k - 1 times, then the one on the 
// top is our target. The first one is min-heap and the second one is max-heap.
// In STL, both priority_queue and multiset can be used as a min/max-heap.



// APPROACH 2 MIN-heap priortiy queue

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




// APPROACH 3

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k-1];
    }
};




// APPROACH 4

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {    
        partial_sort(nums.begin(), nums.begin() + k , nums.end(), greater<int>());
        return nums[k-1];
   
    }
};




// APPROACH 5 

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[n-k];
    }
};




// APPROACH 6

class Solution {
public:
    int quick_sort(vector<int>& nums, int L, int R, int k) {
        if(L == R) return nums[L];
        int i = L-1;
        int j = R+1;
        int x = nums[(i+j) >> 1];
        
        while(i < j){
            do i++; while(nums[i] > x);
            do j--; while(nums[j] < x);
            if(i < j) swap(nums[i],nums[j]);
        }

        int ll = j - L + 1;
        if(ll >= k) return quick_sort(nums, L, j, k);
        return quick_sort(nums, j+1, R, k-ll);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size()-1, k);
    }
};






