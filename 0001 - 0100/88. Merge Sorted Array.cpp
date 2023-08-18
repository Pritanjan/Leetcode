// APPROACH 1

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


// OR


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};


// OR


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        for(i=0; i<n; i++) {
            int num = nums2[i];
            for(j=m+i-1; j>=0 && nums1[j] > num; j--) {
                nums1[j+1] = nums1[j];
            }
            nums1[j + 1] = num;
        }
    }
};






// APPROACH 2  [  In-place with Two Pointers (Backward) ]

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index of last element in nums1
        int j = n - 1; // Index of last element in nums2
        int k = m + n - 1; // Index of last element in merged array

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } 
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them to nums1
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};



// OR
// In-place with Two Pointers (Forward)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;

        vector<int> temp(nums1);

        while(i < m && j < n) {
            if(temp[i] <= nums2[j]) {
                nums1[k] = temp[i];
                i++;
            } 
            else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (i < m) {
            nums1[k] = temp[i];
            i++;
            k++;
        }

        while(j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};







// APPROACH 3

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






// APPROACH 4

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while(p1 < m || p2 < n) {
            if(p1 == m) cur = nums2[p2++];
            else if(p2 == n) cur = nums1[p1++];
            else if(nums1[p1] < nums2[p2]) cur = nums1[p1++];
            else cur = nums2[p2++];
            sorted[p1 + p2 - 1] = cur;
        }

        for(int i=0; i!=m+n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};






// APPROACH 5

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        int temp[m+n];

        while(i < m && j < n) temp[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while(i<m) temp[k++] = nums1[i++];        
        while(j<n) temp[k++] = nums2[j++];
        while(k--) nums1[k] = temp[k];
    }
};






// APPROACH 6

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<m; i++) pq.push(nums1[i]);
        for(int i=0; i<n; i++) pq.push(nums2[i]);
        for(int i=0; i<m+n; i++) {
            nums1[i] = pq.top();
            pq.pop();
        }
    }
};


