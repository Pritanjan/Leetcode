class Solution {
public:
    int binary_search(vector<int>& nums2, int n, int i){
        int L = i;
        int R = nums2.size() - 1;
       
        while(L <= R){
            int mid = L + (R - L)/2;
            if(n <= nums2[mid])
                L = mid + 1;
            else
                R = mid - 1;
        }
        return L;
    
    }
        
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0; i<nums1.size(); i++){
            int j = binary_search(nums2, nums1[i], i);
                ans = max(ans, j-i-1);
        }
        return ans;
    }
};


