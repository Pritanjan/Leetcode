[169. Majority Element II](https://leetcode.com/problems/majority-element/)
[My Github Repoistory](https://github.com/Pritanjan/Leetcode)
**Company Tag -**

<hr>

##### APPROACH 1 Brute Force Approach (TLE)

**Explanation : -**
* The basic idea is to traverse the array and count the frequency of each element. 

* Then use 2 nested loops till `nums.size()` and store the count of each array element in `maxCoun`’. If for any element, `maxCount` becomes greater than `nums.size() / 2 `, Then return that element as the majority element. 

* Else  return -1.

<br>

**Code**
```

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int maxCnt = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == nums[j])
                    maxCnt++;
            }
            
            if(maxCnt > nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};


```

<br>

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N^2)`,  where `N` is the number of elements in the given array.
Since we are running two nested loops till ‘N’ to count the frequency of each element. Thus the overall time complexity is O(N^2).

* **Space Complexity :-** ` O(1)`
As constant space is used, space complexity will be O(1).

<br><hr>

##### APPROACH 2 Using hash map

**Explanation : -**

* We will maintain a hashmap to store element-frequency pairs. We will traverse the array and store the frequency of each element in the hashmap. 

* If the frequency of any element becomes greater than the ` n / 2`, we will return it as the majority element. 

* else return -1.

<br>

**Code**
```

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
		
		// Declaring unordered map to store the frequency of elements.
		unordered_map<int, int> mp;
        // it can also be used
		// map<int,int> mp;  
        
		// Iterating each element in the array to count frequencies.
        for(int i=0;i<n;i++)
			// Storing frequency of each element.
            mp[a[i]]++;
        
        int ans=-1;
        
        for(auto x: mp) {
			// If frequency of the element is greater than 'n' / 2, then return the element.
            if(x.second > (n /2))
                ans=x.first;
        }   
        return ans;
    }
};


```

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N)`,  where `N` is the number of elements in the given array.
Since we are traversing the array exactly one time in O(N) time. Thus the time complexity will be O(N).

* **Space Complexity :-** ` O(N)`
Since we are storing the elements of the array and their respective frequencies in a hashmap. In the worst case, when the array contains `N` distinct elements, then the hashmap takes `O(N)` space. Thus the space complexity will be ` O(N) `.


<br><br><hr>

##### APPROACH 3 - Moore’s voting algorithm

**Explanation : -**
* We can find the majority element in linear time and constant space using ` Moore’s voting algorithm `. It is based on the fact that since the majority element occurs more than floor `(N / 2)` times, its frequency will be greater than the combined frequencies of all other elements `(N = nums.size()) ` .  

* The algorithm gives the correct answer only if the majority element exists in the array. So, in the end, we have to check the frequency of the majority element to confirm.

* The steps are as follows:
   *  We will maintain `maj` to keep track of the majority element.
	* We will initialize ‘count’ to 0 to store the count of ‘majorityElement'.
	* Now, Traverse through array
	   * If `count` is 0:
			* We set  `maj` to the current element, set `count` to `1`, and continue iterating.
		* Else:
			* If the current element is equal to the  `maj,` we increment the `count` by `1`.
			*  Else, we decrement the  `count` by `1`.
* Now, return  `maj`.


**Code**

```

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		// Variable to store the majority element in the array, it it is present.
        int maj = 0;
        int count = 0;
        
		// Iterating the array to know if there is a possible majority element present.
        for(int i=0; i<nums.size(); i++){
			// If count becomes 0, set current element as a possible candidate for majority element, reset count to 1.
            if(count == 0)
                maj = nums[i];
				
			// Increment the count if the current element of the array is equal to the current majority element, else decrement it.
            if(maj == nums[i])
                count++;
            else
                count--;
        }
        return maj;
    }
};

```

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  ` O(N), `   Boyer-Moore performs constant work exactly n times, so the algorithm runs in linear time.

* **Space Complexity :-** ` O(1) `
Boyer-Moore allocates only constant additional memory.

<br><br><hr>

##### APPROACH 4  - STL
**Explanation : -**


**Code**
```

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};

```

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  ` O(N log N), `  where `N` is the number of elements in the given array.

<br>

[229. Majority Element II](https://leetcode.com/problems/majority-element-ii/)

##### APPROACH  1  Using hash map
**Explanation : -**

* We will maintain a hashmap to store element-frequency pairs. We will traverse the array and store the frequency of each element in the hashmap. 

* If the frequency of any element becomes greater than the ` n / 3`, we will return it as the majority element. 

* else return -1.

<br>

**Code**

```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> um;
        // map<int, int> um;
        
        for(auto i : nums)
            um[i]++;
        
        for(auto it : um)
            if(it.second > n/3){
                v.push_back(it.first);
            }
        return v;
        
        
    }
};

```

##### COMPLEXITY ANALYSIS : -
* **Time Complexity : -**  `O(N)`,  where `N` is the number of elements in the given array.
Since we are traversing the array exactly one time in O(N) time. Thus the time complexity will be O(N).

* **Space Complexity :-** ` O(N)`
Since we are storing the elements of the array and their respective frequencies in a hashmap. In the worst case, when the array contains `N` distinct elements, then the hashmap takes `O(N)` space. Thus the space complexity will be ` O(N) `.

<br><br>
