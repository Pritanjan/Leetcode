// A 1 

// Arrays are sorted so increase i while nums1[i] is bigger than nums2[j], and 
// increment j otherwise.

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, ans = 0;
        while(i<nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]) i++;
            else ans = max(ans, j++ - i);
        }
        return ans;
    }
};






// A 2 

class Solution {
public:
    int binary_search(vector<int>& nums2, int n, int i){
        int L = i;
        int R = nums2.size() - 1;
        while(L <= R){
            int mid = L + (R - L)/2;
            if(n <= nums2[mid]) L = mid + 1;
            else R = mid - 1;
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

