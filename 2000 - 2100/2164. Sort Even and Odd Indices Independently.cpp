// A 1 - Using Two Separate Vectors for Odd and Even Indices

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even, odd;
        
        for(int i=0; i<n; i++){
            if(i%2 == 0) even.push_back(nums[i]);   
            else odd.push_back(nums[i]);    
        }        
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());        
        for(int i=0,j=0; i<n; i+=2) nums[i] = even[j++];
        for(int i=1,j=0; i<n; i+=2) nums[i] = odd[j++];    
        return nums;
    }
};

// TC : O(NlogN) , SC : O(N)


// OR

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> oddIdx, evenIdx;
        
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) evenIdx.push_back(nums[i]);
            else oddIdx.push_back(nums[i]);
        }
        
        // Manual sorting for evenIndices in non-decreasing order
        for(int i=0; i<evenIdx.size(); ++i) {
            for(int j=i+1; j<evenIdx.size(); ++j) {
                if(evenIdx[i] > evenIdx[j]) {
                    swap(evenIdx[i], evenIdx[j]);
                }
            }
        }
        
        // Manual sorting for oddIndices in non-increasing order
        for(int i=0; i<oddIdx.size(); ++i) {
            for(int j=i+1; j<oddIdx.size(); ++j) {
                if(oddIdx[i] < oddIdx[j]) {
                    swap(oddIdx[i], oddIdx[j]);
                }
            }
        }
        
        int oddIndex = 0, evenIndex = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) nums[i] = evenIdx[evenIndex++];
            else nums[i] = oddIdx[oddIndex++];
        }        
        return nums;
    }
};






// A 2  - Using Priority Queues (Min and Max Heaps)

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) minHeap.push(nums[i]);
            else maxHeap.push(nums[i]);
        }
        
        for(int i=0; i<nums.size(); ++i) {
            if(i % 2 == 0) {
                nums[i] = minHeap.top();
                minHeap.pop();
            } 
            else {
                nums[i] = maxHeap.top();
                maxHeap.pop();
            }
        }        
        return nums;
    }
};






// A 3



