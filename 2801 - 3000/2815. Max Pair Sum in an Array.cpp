// APPROACH 1

class Solution {
public:
    int maxDigit(int n) {
        int mx = 0;
        while(n > 0) {
            mx = max(mx, n % 10);
            n /= 10;
        }
        return mx;
    }

    int maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v[10]; 

        for(int num : nums) {
            int mx = maxDigit(num);
            v[mx].push_back(num);
        }

        int maxSum = -1;
        for(int i=1; i<=9; ++i) {
            int Size = v[i].size();
            if(Size < 2) continue;

            sort(v[i].rbegin(), v[i].rend()); 
            int sum = v[i][0] + v[i][1];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    } 
};






// APPROACH 2

