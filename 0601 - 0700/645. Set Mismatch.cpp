// SEE EDITORIL

// A 0 [ BRUTE FORCE - TLE ]

// The most naive solution is to consider each number from 1 to N, and
// traverse over the whole nums array to check if the current number occurs twice in nums
// or doesn't occur at all. We need to set the duplicate number, dup and the missing number, 
// missing, appropriately in such cases respectively.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        for(int i=1; i<=n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(nums[j] == i) 
                    count++;
            }
            
            if(count == 2) res[0] = i;
            else if(count == 0) res[1] = i;
        }
        return res;
    }
};

// T.C. --> O(N^2) 
// S.C. --> O(1) 






// A 1 [ BETTER BRUTE FORCE ]

// In the previous code, I continued the search process, even after finding the duplicate and
// the missing number. Since, only one no is repeated missing. 
// Thus, It can be optimize by stopping the search process as soon as we find these two numbers.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        for(int i=1; i<=n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(nums[j] == i) 
                    count++;
            }

            if(count == 2) res[0] = i;
            else if(count == 0) res[1] = i;

            if(res[0] > 0 && res[1] > 0) break;
        }
        return res;
    }
};

// T.C. --> O(N^2) 
// S.C. --> O(1) 






// A 2

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1);
        for(int i=0; i<nums.size(); i++){
            while(nums[i] != i+1){
                if(nums[i] == nums[nums[i] - 1]){
                    // ans.push_back(nums[i]);
                    // ans.push_back(i + 1);
                    ans[0] = nums[i];
                    ans[1] = i + 1;
                    break;
                }
                else swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return ans;
    }
};

// T.C. --> O(N) 
// since it involves only one loop through the nums array. 
// Within the loop, the inner while loop may iterate up to O(n) times .
// In the worst case scenario where all numbers are out of place,
// but since each number is moved to its correct position at most once, 
// the overall time complexity is still O(n).

// S.C. --> O(1) 
// it uses a constant amount of extra space to store the ans vector with two elements.






// A 3

// The code first creates a boolean array found of size n+1, where found[i] 
// represents whether the number i has been found in the nums array.

// It then iterate through the nums array, and for each element in nums[i],
// if found[nums[i]] is already true, then nums[i] is the duplicate number, 
// and is stored in res[0]. Otherwise, it sets found[nums[i]] to true.

// Finally, it loops through the found array from 1 to n, and if it finds an index i 
// where found[i] is false, then i is the missing number, and is stored in res[1].

// The function returns the res array containing the duplicate and missing numbers.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        vector<bool> found(n+1, false);

        for(int i=0; i<n; i++) {
            if(found[nums[i]]) {
                res[0] = nums[i];
            }
            found[nums[i]] = true;
        }

        for(int i=1; i<=n; i++){
            if(!found[i]) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};

// T.C. --> O(N), where n is the size of the nums vector.
// This is because the solution iterates through the nums vector twice,

// S.C. --> O(N),
// since it uses a boolean vector found of size n + 1 to keep track of which
// numbers have been found. This requires O(n) extra space.







// A 4

class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        vector<int> ans;
        sort(A.begin(), A.end());
        
        for(int i=0; i<A.size()-1; i++){
            if(A[i] == A[i+1])
                ans.push_back(A[i]);
        }
        
        for(int i=1; i<=A.size(); i++){
            if(!binary_search(A.begin(), A.end(), i))
                ans.push_back(i);
        }      
        return ans;
    }
};



