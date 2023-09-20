// A 1

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int target = -x;
        for(auto i : nums) target += i;
        if(target < 0) return -1;
        
        int j = 0;
        // int sum = accumulate(nums.begin(),nums.end(),0); 
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum > target){
                sum -= nums[j];
                j++;
            }
            if(sum == target) ans = max(ans, i-j+1);
        }         
        return ans==INT_MIN ? -1 : nums.size() - ans;
    }
};






// A 2

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;

        int L = 0, R = 0, maxn = -1;
        while(R < n) {
            target -= nums[R++];
            while(target < 0) target += nums[L++];
            if(target == 0) maxn = max(maxn, R - L);
        }
        return (maxn == -1) ? maxn : n - maxn;
    }
};






// A 3

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int n : nums) {
            sum += n;
        }
        x = sum - x;
        int n = nums.size();
        
        if(x == 0) return n;
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }

        int res = numeric_limits<int>::max();
        unordered_map<int, int> map;
        map[0] = -1;

        for(int i=0; i<n; i++) {
            int need = nums[i] - x;
            if(map.count(need)) {
                int size = i - map[need];
                res = min(res, n - size);
            }
            map.emplace(nums[i], i);
        }
        return res == numeric_limits<int>::max() ? -1 : res;
    }
};






// A 4

class Solution {
public:
    int INF = 1000000;
    int binarySearch(int R, vector<int>& v,int target) {
        // return operations to find the value
        int L = 0, mid;
        while(L <= R) {
            mid = L + (R - L) / 2;
            if(v[mid] == target) return mid + 1;
            else if(v[mid] < target) L = mid + 1;
            else R = mid-1;
        }
        return INF;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> v(n, 0);
        v[0] = nums[0];
        for(int i=1; i<n; i++) v[i] = v[i-1] + nums[i];

        if(v[n-1] < x)  return -1;
        if(v[n-1] == x) return n;
        int op = n;
        
        for(int i=n; i>=0; i--) {
            if(i != n) x += - nums[i];
            if(x == 0) op = min(op, n-i);
            if(x < 0) break;
            int Lop = binarySearch(i-1, v, x);

            op = min(op, n - i + Lop);
        }
        return op == n ? -1 : op;
    }
};


