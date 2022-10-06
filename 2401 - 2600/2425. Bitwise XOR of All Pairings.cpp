// https://leetcode.com/problems/bitwise-xor-of-all-pairings/



// APPROACH 1 TLE 
class Solution {
public:
    int xorAllNums(vector<int>& A1, vector<int>& A2) {
        long long n = A1.size();
        long long m = A2.size();
        
//         vector<int> v(n+m);
        
//         for(int i=0; i<n; i++){
//             v.push_back(nums1[i]);
//         }
//         for(int i=n; i<m; i++){
//             v.push_back(nums2[i]);
//         }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int temp = A1[i] ^ A2[j];
                
                ans = ans ^ temp;
            }
        }
        return ans;
    }
};



// APPROACH 2

class Solution {
public:
    int xorAllNums(vector<int>& A1, vector<int>& A2) {
        long long n = A1.size();
        long long m = A2.size();
        
        map<long, long> mp;
        
        // Pairing all the element of A1 to A2
        for(auto i : A1)
            mp[i] += m;
        
        for(auto i : A2)
            mp[i] += n;

        for(auto i : mp)
            mp[i.first] %= 2;
        
        long long ans = 0;
        
        for(auto i : mp){
            if(i.second == 1){
                ans = ans ^ i.first;
            }
        }
        return (int)ans;
    }
};


// APPROACH 3 

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums1.size()&1) {
            for (int i : nums2) ans ^= i;
        }
        if (nums2.size()&1) {
            for (int i : nums1) ans ^= i;
        }return ans;
    }
};
