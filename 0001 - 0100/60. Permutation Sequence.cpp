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






// APPROACH 2 

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






// APPROACH 3 



