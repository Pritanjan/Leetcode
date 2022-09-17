// https://leetcode.com/problems/majority-element/


// APPROACH 1 Brute Force  -> TLE
class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        for(int i : a){
            int cnt = 0;
            for(int j : a){
                if(i == j)
                    cnt++;
            }
            if(cnt > n/2)
                return i;
        }
        return -1;
    }
};


// APPROACH 2   Boyer-Moore Voting

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int count = 0;
        
        // for(auto i : nums){
        for(int i=0; i<nums.size(); i++){
            
            if(count == 0)
                maj = nums[i];
            
            if(maj == nums[i])
                count++;
            else
                count--;
        }
        return maj;
    }
};

// Time complexity : O(n) 
// Boyer-Moore performs constant work exactly nn times, so the algorithm runs in linear time.
// Space complexity : O(1) 
// Boyer-Moore allocates only constant additional memory.



// APPROACH 3 Using STL

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};



// APPROACH 4

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int ans=-1;
        
        for(auto x: mp) {
        if(x.second > (n /2))
            ans=x.first;
        }
        return ans;
    }
};







