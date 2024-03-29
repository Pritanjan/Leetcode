// A 1 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        vector<int> prod(n);
        
        for(int i = 0; i<n; i++){
            prod[i] = prefix;
            prefix*=nums[i];
        }
        
        for(int i=n-1; i>=0; i--){
            prod[i]*=suffix;
            suffix*=nums[i];
        }
        
        return prod;
    }
};






// A 2 

#define ll long long int 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll pdt = 1;
        int zeroCnt = 0; // Count the number of zeros in the array
        for(auto i : nums) {
            pdt *= (i == 0 ? 1 : i); // If i is zero, don't multiply, just keep track of the zero count
            if(i == 0) zeroCnt++;
        }

        vector<int> res;
        for(int i : nums) {
            if(i == 0) {
                // If i is zero, the result is product of all elements except the current zero
                res.push_back(zeroCount == 1 ? pdt : 0);
            } 
            else {
                // If i is not zero, the result is total product divided by i
                res.push_back(zeroCnt == 0 ? pdt / i : 0);
            }
        }
        return res;
    }
};






// A 3  -  Left and Right Product Arrays

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> LPdt(n, 1);
        vector<int> RPdt(n, 1);
        vector<int> res(n, 1);

        // Calculate the product of all elements to the left of each element
        int L = 1;
        for(int i=1; i<n; ++i) {
            L *= nums[i-1];
            LPdt[i] = L;
        }

        // Calculate the product of all elements to the right of each element
        int R = 1;
        for(int i=n-2; i>=0; --i) {
            R *= nums[i+1];
            RPdt[i] = R;
        }

        // Multiply the left and right products to get the final result
        for(int i=0; i<n; ++i) {
            res[i] = LPdt[i] * RPdt[i];
        }
        return res;
    }
};






// A 4

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int L = 1;
        int R = 1;
        for(int i=0; i<n; ++i) {
            res[i] *= L;
            L *= nums[i];
        }

        for(int i=n-1; i>=0; --i) {
            res[i] *= R;
            R *= nums[i];
        }
        return res;
    }
};
