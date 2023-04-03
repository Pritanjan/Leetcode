// APPROACH 1

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int > s;
        for(int &p : nums)
            s.insert(p);
        
        // if(s.size()<3)
        //     return *max_element(s.begin(), s.end());
        // else
        //     *next(s.begin(), s.size()-3);
         return s.size()<3 ? *max_element(s.begin(),s.end()) : *next(s.begin(), s.size() - 3);
    }
};


// T.C. --> O(nlogn) - 
// the algorithm iterates through each element in the input array once and inserts each element
// into a set, which has a worst-case time complexity of O(logn) for each insertion. 
// Since the set is of size at most 3, finding the third maximum element has a T.C. of O(1) 
// if the set size is greater than or equal to 3, and O(nlogn) 
// if the set size is less than 3 due to the use of max_element().

// Space complexity: O(n) - 
// the algorithm uses a set to store unique elements from the input array, 
// which can have a size of up to n in the worst case if all elements are unique.







// APPROACH 2 [ SOLUTION APPROACH 3 ]


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Initialize a min heap and an unordered set.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> taken;
        
        // Iterate over each element in 'nums'.
        for (int index = 0; index < nums.size(); ++index) {
            // If current number was already taken, skip it.
            if (taken.count(nums[index])) {
                continue;
            }
            
            // If min heap already has three numbers in it.
            // Pop the smallest if current number is bigger than it.
            if (minHeap.size() == 3) {
                if (minHeap.top() < nums[index]) {
                    taken.erase(minHeap.top());
                    minHeap.pop();
                    
                    minHeap.push(nums[index]);
                    taken.insert(nums[index]);
                }
            } 
            // If min heap does not have three number we can push it.
            else {
                minHeap.push(nums[index]);
                taken.insert(nums[index]);
            }
        }
        
        // 'nums' has only one distinct element it will be the maximum.
        if (minHeap.size() == 1) {
            return minHeap.top();
        }
        // 'nums' has two distinct elements.
        else if (minHeap.size() == 2) {
            int firstNum = minHeap.top();
            minHeap.pop();
            return max(firstNum, minHeap.top());
        }
        
        // 'nums' has three or more distinct elements.
        return minHeap.top();
    }
};





