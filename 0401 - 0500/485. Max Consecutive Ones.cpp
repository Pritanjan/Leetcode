// APPROACH 1

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                ans = max(ans, cnt);
            }
            else cnt = 0;
        }
        return ans;
    }
};






// APPROACH 2

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        string s = "";
        for (int i=0; i<nums.size(); i++) {
            s += to_string(nums[i]);
        }

        vector<string> substrings;
        string temp = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '0') {
                substrings.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        substrings.push_back(temp);
        
        int max_len = 0;
        for (int i=0; i<substrings.size(); i++) {
            if (substrings[i].size() > max_len) {
                max_len = substrings[i].size();
            }
        }
        return max_len;
    }
};







// APPROACH 3

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] == 1) {
                r++;
                res = max(r - l, res);
            } else {
                r++;
                l = r;
            }
        }
        return res;
    }
};






// APPROACH 4

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int maximum = 0;
        for (int num : nums) {
            cur = (cur + num) * num;
            if (cur > maximum) {
                maximum = cur;
            }
        }
        return maximum;
    }
};







