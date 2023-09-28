// A 1 - Binary Search

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R){
            if(nums[L] % 2 != 0) {
                swap(nums[L], nums[R]);
                R--;
            }
            else L++;
        }
        return nums;
    }
};






// A 2  -  Partition Approach

class Solution {
public:
   vector<int> sortArrayByParity(vector<int>& nums) {
       for (int i = 0, j = 0; j < nums.size(); j++)
           if (nums[j] % 2 == 0) swap(nums[i++], nums[j]);
       return nums;
   }
};

// TC = O(N)






// A 3

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2 == 0)
                ans.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2 != 0)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};


// OR


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        for (int num : nums) {
            if (num % 2 == 0) even.push_back(num);
            else odd.push_back(num);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }     
};






// A 4 - 2 Pointer

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while(L < R) {
            while(L < R && nums[L] % 2 == 0) L++;
            while(L < R && nums[R] % 2 != 0) R--;
            if(L < R) {
                swap(nums[L], nums[R]);
                L++;
                R--;
            }
        }
        return nums;
    }
};






// A 5 - Use Bitwise AND - implementation is same as A 4

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while(L < R) {
            while(L < R && nums[L] & 1 == 0) L++;
            while(L < R && nums[R] & 1 != 0) R--;
            if(L < R) {
                swap(nums[L], nums[R]);
                L++;
                R--;
            }
        }
        return nums;
    }
};


// OR 
// Using Bitwise XOR

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int xorSum = 0;
        for(int num : nums) {
            xorSum ^= (num % 2);
        }

        int evenIdx = 0;
        for(int i=0; i<nums.size(); i++) {
            if((nums[i] % 2) == xorSum) {
                swap(nums[i], nums[evenIdx++]);
            }
        }
        return nums;
    }
};





// A 6 - STL 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        return nums;
    }
};


// OR


class Solution {
public:
    static bool isEven(int num) {
        return num % 2 == 0;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), isEven);
        return nums;
    }    
};


// OR


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return (a % 2 == 0 && b % 2 != 0);
        });
        return nums;
    }
};






// A 7

class Solution {
public:
    static bool evenFirst(int a, int b) {
        return (a % 2 == 0 && b % 2 != 0);
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), evenFirst);
        return nums;
    }
};






// A 8 -  Counting 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenCount = 0;
        for(int num : nums) {
            if(num % 2 == 0) {
                evenCount++;
            }
        }

        int n = nums.size();
        vector<int> res(n);
        int evenIdx = 0, oddIdx = evenCount;
        for(int num : nums) {
            if(num % 2 == 0) res[evenIdx++] = num;
            else res[oddIdx++] = num;
        }
        return res;
    }
};


// OR


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int evenIdx = 0, oddIdx = n-1;
        for(int num : nums) {
            if(num % 2 == 0) res[evenIdx++] = num;
            else res[oddIdx--] = num;
        }
        return res;
    }
};





// A 9 - Using Iterators 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto evenPos = nums.begin();
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if ((*it) % 2 == 0) {
                swap(*it, *evenPos);
                evenPos++;
            }
        }
        return nums;
    }
};



