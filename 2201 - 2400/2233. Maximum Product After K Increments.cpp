// https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution {
public:
 int maximumProduct(vector<int>& nums, int k) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& i : nums)
        pq.push(i);
    
    while(k--){
        int p = pq.top();
        pq.pop();
        pq.push(p + 1);
    }
    
   long long ans = 1;
    while(!pq.empty()){
        ans = (ans * pq.top()) % 1000000007;
        pq.pop();
    }
    return ans;
  }
};







// To get the largest product we need to increment the smallest number we have. To get the smallest number always min heap can be used.

