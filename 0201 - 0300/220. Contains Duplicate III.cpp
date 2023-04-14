// APPROACH 1  [ BRUTE FORCE -- TLE ]

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(i != j && abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) return true;
            }
        }
        return false;
    }
};







// APPROACH 2


// Here, we are using set to store the values seen so far within the required range.
// We maintain a sliding window of size indexDiff using s.erase(nums[i-indexDiff-1]) to 
// remove elements that are no longer in the window.


//  We then use s.lower_bound((long long)nums[i] - valueDiff) to find the first element >= 
// to nums[i] - valueDiff, and 
// check if it is within the range by verifying *it - nums[i] <= valueDiff. 
// If we find such an element, we return true.
// If not, we add the current element to the set and continue.



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> s;
        
        for(int i=0; i<nums.size(); i++) {
            if(i > indexDiff) s.erase(nums[i-indexDiff-1]);
            
            auto it = s.lower_bound((long long)nums[i] - valueDiff);
            if(it != s.end() && *it - nums[i] <= valueDiff) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};


// T.C. -- > O(n*log(indexDiff))
// S.C. --> O(indexDiff)






// APPROACH 3 [ 2 POINTER ]

class Solution {
public:       
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        int i = 0, j = 0;

        while(i < n && j < n) {
            if(i != j && abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff)  return true;
            if(j - i <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) j++;
            else i++;
        }
        return false;
    }
};




// T.C. --> O(n)
// S.C. --> O(1)







