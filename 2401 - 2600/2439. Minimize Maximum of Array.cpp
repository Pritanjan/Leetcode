// APPROACH 1


class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        auto check = [&](int mx) {
            long d = 0;
            for (int i = nums.size() - 1; i; --i) {
                d = max(0l, d + nums[i] - mx);
            }
            return nums[0] + d <= mx;
        };

        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


// OR


class Solution {
public:
    long check(vector<int>& nums, int mx) {
        long d = 0;
        for (int i=nums.size()-1; i; --i) {
            d = max(0l, d + nums[i] - mx);
        }
        return d;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) >> 1;
            long d = check(nums, mid);
            if (nums[0] + d <= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)



// APPROACH 2

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // Initialize answer and the prefix sum.
        long long answer = 0, prefixSum = 0;
        
        // Iterate over nums, update prefix sum and answer.
        for(int i=0; i<nums.size(); ++i) {
            prefixSum += nums[i];
            answer = max(answer, (prefixSum + i) / (i + 1));
        }        
        return answer;
    }
};


// T.C. --> O(N)
// S.C. --> O(1)
