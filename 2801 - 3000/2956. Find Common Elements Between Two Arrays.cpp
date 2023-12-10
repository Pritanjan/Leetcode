// https://leetcode.com/contest/biweekly-contest-119/ranking/

// A 1 

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        for(auto i : nums1) mp1[i]++;
        unordered_map<int, int> mp2;
        for(auto i : nums2) mp2[i]++;

        int cnt1 = 0;
        for(int i=0; i<nums1.size(); i++) {
            if(mp2.find(nums1[i]) != mp2.end()) cnt1++;
        }

        int cnt2 = 0;        
        for(int i=0; i<nums2.size(); i++) {
            if(mp1.find(nums2[i]) != mp1.end()) cnt2++;
        }
        return {cnt1, cnt2};
    }
};





// A 2

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {        
        set<int> A, B;
        for (int x : nums1) A.emplace(x);
        for (int x : nums2) B.emplace(x);
        
        int c = 0, d = 0;
        for(int x : nums1) if(B.contains(x)) c++;
        for(int x : nums2) if(A.contains(x)) d++;
        return vector<int>{c, d};
    }
};

// OR

// class Solution {
// public:
//     vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {        
//         set<int> A, B;
//         for (int x : nums1) A.insert(x);
//         for (int x : nums2) B.insert(x);
        
//         int c = 0, d = 0;
//         for(int x : nums1) if(B.count(x)) c++;
//         for(int x : nums2) if(A.count(x)) d++;
//         return {c, d};
//     }
// };






// A 3

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans{0, 0};
        for(int num : nums1) {
          ans[0] += count(nums2.begin(), nums2.end(), num) > 0;
        }
        for(int num : nums2) {
          ans[1] += count(nums1.begin(), nums1.end(), num) > 0;
        }
        return ans;
    }
};






// A 4

