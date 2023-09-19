// A 0  -  Brute Force Approach:
// iterate through array, keeping track of the current consecutive count of 1's and 
// updating the maximum count as you go.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int currCnt = 0;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == 1) {
                int j = i;
                while(j < nums.size() && nums[j] == 1) j++;
                currCnt = j - i;
                maxCnt = max(maxCnt, currCnt);
                i = j;
            } 
            else i++;
        }        
        return maxCnt;
    }
};






// A 1  Linear Scan
// Traverse the array linearly and keep track of the current consecutive count of 1's and
// the maximum consecutive count encountered.

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






// A 2

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
            } 
            else temp += s[i];
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






// A 3

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;
        while(r < nums.size()) {
            if(nums[r] == 1) {
                r++;
                res = max(r - l, res);
            } 
            else {
                r++;
                l = r;
            }
        }
        return res;
    }
};






// A 4

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int currCnt = 0;        
        for(int num : nums) {
            // currCnt = (currCnt + 1) * num;
            currCnt = (currCnt + num) * num;
            maxCnt = max(maxCnt, currCnt);
        }        
        return maxCnt;
    }
};






// A 5 Sliding Window:
// WE can use a sliding window approach to keep track of the current window of consecutive 1's and
// update the maximum count.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int j = 0;  // windowStart
        for(int i=0; i<nums.size(); i++) {    // windowEnd
            if(nums[i] == 0) j = i+1;
            else mx = max(mx, i-j+1);
        }        
        return mx;
    }
};






// A 6 
// Use find function to locate the 1st occurrence of 0 in array & calculate the maximum consecutive 1's before that position.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int currCnt = 0;        
        auto zeroPos = find(nums.begin(), nums.end(), 0);
        for(auto it=nums.begin(); it!=nums.end(); ++it) {
            if(it == zeroPos) {
                maxCnt = max(maxCnt, currCnt);
                currCnt = 0;
                zeroPos = find(zeroPos + 1, nums.end(), 0);
            }
            currCnt += *it;
        }        
        return max(maxCnt, currCnt);
    }
};






// A 7 - 
// convert the binary array to a string and then split it based on '0'. 
// The maximum length of consecutive ones will be the length of the longest substring of '1's.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        string s;
        for (int num : nums) {
            s += to_string(num);
        }
        stringstream ss(s);
        string token;
        int maxCount = 0;
        
        while(getline(ss, token, '0')) {
            maxCount = max(maxCount, static_cast<int>(token.size()));
        }        
        return maxCount;
    }
};






// A 8


