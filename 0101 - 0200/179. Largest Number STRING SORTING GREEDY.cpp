// A 1 - Lambda Function with Sorting:
// You can use a lambda function in the sorting to achieve the same result.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> v(n);

        // Convert integers to strings
        for(int i=0; i<n; i++){
            v[i] = to_string(nums[i]);
        }

        // Sort using a lambda function
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return ((a+b) > (b+a));
        });

        // Concatenate sorted strings to form the largest number
        string ans = "";
        for(auto i : v) ans += i;

        // Else handle the case where all numbers are 0
        return ans[0] == '0' ? "0" : ans;
    }
};






// A 2
