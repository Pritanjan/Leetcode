// https://leetcode.com/problems/subarray-sum-equals-k/

// return the total number of subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        unordered_map<int, int> ump;
        int sum = 0;
        int ans = 0;
        ump[sum] = 1;
        
        for(int i=0; i<A.size(); i++){
            sum += A[i];
            if (ump.find(sum - k) != ump.end()) {
                ans += ump[sum - k];
            }
            ump[sum]++;
        }
        return ans; 
    }
};


// return subarrays whose sum equals to k.
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category[]=Arrays&sortBy=submissions
// Company Tags - Amazon Facebook Google Visa

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int A[], int n, long long k)
    {
        int L = 0;
        int R = 0;
        int sum = 0;
        
        while(L < n){
            sum += A[L];
            
            if(sum == k)
                return {R+1, L+1};
            if(sum > k){
                sum = 0;
                R++;
                L = R - 1;
            }
            L++;
        }
        return {-1};
    }
};






