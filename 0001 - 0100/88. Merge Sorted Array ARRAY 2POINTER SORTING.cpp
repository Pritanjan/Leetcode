class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {       
        int j=0;
        for(int i=m;i<nums1.size();i++){
            if(j<n){
                nums1[i]=nums2[j] ;
            }
            j++;
        }
        sort(nums1.begin(),nums1.end());   
    }    
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        merge1(nums1, m, nums2, n);
    }

    vector<int> merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n);

        for(int i=0; i<m; i++) v[i] = nums1[i];
        for(int i=0; i<n; i++) v[m+i] = nums2[i];
    
        sort(v.begin(), v.end());

        // Copy the sorted values back to nums1
        for(int i=0; i<m+n; i++) nums1[i] = v[i];

        return nums1;
    }
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1.merge(nums2)
        //     return nums;
        
//         vector<int> :: iterator it;
        
//         vector<int> nums(m+n);
//         it = set_union(nums1.begin(), nums1.end(), nums2.end(),nums2.end(),nums.begin());
//         sort
//         for(int st = nums.begin(); st!=it; ++st)
//             return st;
        
        int j=0;
        for(int i=m;i<nums1.size();i++){
            if(j<n){
                nums1[i]=nums2[j] ;
            }
            j++;
        }
        sort(nums1.begin(),nums1.end());
        
        
        
    }
//     return -1;
    
};

