// APPROACH 1 

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n-1);
        int fact = 1;
        
        for(int i=1; i<n; i++){
            nums[i-1] = i;
            fact *= i;
        }
        nums.push_back(n);
        string ans = "";
        k--;

        while(1){
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if(nums.size() == 0) break;
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};






// APPROACH 2 - Generating Permutations

// Generate all permutations of the sequence [1, 2, ..., n] and then return the kth permutation. 
// We can use the next_permutation function to generate permutations. 
// But, this approach might be inefficient for large values of n and k.

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        for(int i=1; i<=n; ++i) {
            res += to_string(i);
        }

        for(int i=1; i<k; ++i) {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};






// APPROACH 3 - Using Factorials
// It takes advantage of the factorial property. 
// Given n distinct elements, there are (n-1)! permutations that start with each of the n elements. 
// We can calculate the digits of the kth permutation using this property.

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums;
        for(int i=1; i<=n; ++i) {
            nums.push_back(i);
        }

        k--;  // Convert k to 0-based index
        int fact = 1;
        for(int i=2; i<n; ++i) {
            fact *= i;
        }

        for(int i=n-1; i>0; k %= fact, fact /= i, --i) {
            int idx = k / fact;
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        res += to_string(nums[0]);
        return res;
    }
};






// APPROACH 4 


