// https://leetcode.com/problems/first-missing-positive/
// Company Tag - Amazon Samsung Snapdeal hike
// https://leetcode.com/problems/first-missing-positive/discuss/1928890/c-solution-first-missing-positive

##### APPROACH 1
**Searching (TLE) : -**

```

class Solution {
public:
    bool search(vector<int>& A, int tgt){
        for(int i=0; i<A.size(); i++){
            if(A[i] == tgt)
                return true;
        }
        return false;
    }
        
    int firstMissingPositive(vector<int>& nums) {
        for(int i=1; i<=nums.size(); i++){
            if(search(nums, i) == false)
                return i;
        }
        return nums.size()+1;
    }
};

```


##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N ^ 2)` .
* **Space Complexity : -**  `O(1)` .

<br><hr>


##### APPROACH 2
**IDEA**
 
// Number greater than ` n ` or less than ` 0 ` can be ignored as the missing number
// must be in the range of [1, n+1] if there is no missing number and it is in the range 
// of [1, n], if there is a missing number.`

```

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n;i++){
            while(nums[i] > 0 && nums[i] <=n && nums[nums[i] - 1] != nums[i])
                swap(nums[i] , nums[nums[i]-1]);
        }    
        for(int i=0; i<n;i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};

```
	
	
##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N)` .

<br><hr>

##### APPROACH 3
**SORTING**
**Explanation**

* Sort the `array`.

* Initialize a variable counter with 1, to keep track of the positive integers that are present in the array.

* Traverse the whole array and if the current element is negative or zero then skip the element.

* If the current element is positive and equal to the counter, then increment the counter.

* If the current element is not equal to the counter then return the counter, because the counter will be the smallest positive missing element.

* If the whole array is traversed then return `counter`.

```

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        sort(A.begin(), A.end());
        
        if(A.size() == 0)
            return 1;
        int counter = 1;
        
        for(int i=0; i<A.size(); i++){
            // Skip the negative number.
            if(A[i] < counter)
                continue;
            else if(A[i] == counter){
                counter++;
            }
            // First missing positive number.
            else
                break;
        }
        return counter;        
    }
};

```

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N log(N)), ` as we are sorting  & iterating the whole array.
* **Space Complexity : -**  `O(1)` .

