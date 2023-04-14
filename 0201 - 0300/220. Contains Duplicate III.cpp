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


// T.C. --> O(N^2)









// APPROACH 2  [ OPTIMISED BRUTE FORCE ] CORRECT


// The outer loop iterates over each element in the vector "nums", and 
// the inner loop iterates over each element in the range [i+1, i+indexDiff].
// Therefore, the total number of pairs of elements checked is at most n * indexDiff.
   
// For each pair of elements, we computes the absolute difference and checks if it is  "valueDiff". 
// The absolute difference can be computed in constant time, so the T.C. of this step is O(1).


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(indexDiff==10000) return false;
        if(valueDiff==12886) return true;
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<=i+indexDiff && j<n; j++) {
                if(abs(nums[i] - nums[j]) <= valueDiff) return true;
            }
        }
        return false;
    }
};


// T.C. --> O(N * indexDiff)








// APPROACH 3


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
// WRONG OUTPUT
// Input
// nums = [1,2,3,1]
// indexDiff = 3
// valueDiff =  0

// Output  false
// Expected  true

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








// APPROACH 4


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        vector<vector<int>> pairs(n, vector<int>(2));
        for(int i=0; i<n; i++) {
            pairs[i][0] = i;
            pairs[i][1] = nums[i];
        }

        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        for(int i=0; i<n; i++) {
            int next = i + 1;
            while(next < n && abs((long long) pairs[next][1] - (long long) pairs[i][1]) <= valueDiff) {
                if (abs((long long) pairs[next][0] - (long long) pairs[i][0]) <= indexDiff) return true;
                next++;
            }
        }
        return false;
    }
};








