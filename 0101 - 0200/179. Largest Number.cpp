// A 1 - Lambda Function with Sorting:
// You can use a lambda function in the sorting to achieve the same result.

class Solution {
public:
    static bool compare (string &a, string &b) {
        return a+b > b+a;
    }    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> v(n);

        // Convert integers to strings
        for(int i=0; i<n; i++){
            v[i] = to_string(nums[i]);
        }

        // sort(v.begin(), v.end(), compare);
        // Sort using a lambda function
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return ((a+b) > (b+a));
        });

        // Concatenate sorted strings to form the largest number
        // string ans = "";
        // for(auto i : v) ans += i;

        // Concatenate sorted strings to form the largest number using accumulate
        string ans = accumulate(v.begin(), v.end(), string(""));
        return ans[0] == '0' ? "0" : ans;
    }
};


// OR


class Solution {
public:
    static bool compare (int a,  int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if(nums[0] == 0) return "0";

        stringstream res;
        for(auto num : nums) {
            res << num;
        }
        return res.str();
    }
};


// OR


class Solution {
public:    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if(nums[0] == 0) return "0";
        stringstream res;
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            res << *it;
        }
        return res.str();
    }
};






// A 2

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int num : nums)
            vec.push_back(to_string(num));

        sort(vec.begin(), vec.end(), [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        });

        string ans;
        for(auto &num : vec)
            ans += num;

        // remove leading zeros
        while(ans.front() == '0' && ans.length() > 1)
            ans.erase(0, 1);

        return ans;
    }
};



