// APPROACH 1


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa(begin(A), end(A)), sb(begin(B), end(B));
        vector<vector<int>> ans(2);
        for (int n : sa) {
            if (sb.count(n) == 0) ans[0].push_back(n);
        }
        for (int n : sb) {
            if (sa.count(n) == 0) ans[1].push_back(n);
        }
        return ans;
    }
};







// APPROACH 2 [ MAP ]


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {		
        map<int, int> m1, m2;
        int n = nums1.size();
        int m = nums2.size();
        
        for(auto i : nums1){
            m1[i]++;
        }
        for(auto i : nums2){
            m2[i]++;
        }
        
        vector<int> v;
        vector<vector<int>> ans;
        
        for(auto it : m1){
            if(m2.find(it.first) == m2.end())
                v.push_back(it.first);
        }
        
        ans.push_back(v);
        v.clear();
       
        for(auto it : m2){
            if(m1.find(it.first) == m1.end())
                v.push_back(it.first);
        }
        
        ans.push_back(v);
        return ans;
    }
};









// APPROACH 3 [ SET ]

// Add all elements of both array in a set.
// Then iterate through both array and using find() method, if the element is not found in 
// other set, add it to the answer.
// Do this for both the arrays and return the answer.

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {	   
        unordered_set<int> n1, n2;  // IMPLEMENTING UNORDERED_SETUSING HASH TABLE WHERE KEYS ARE HASHED INTO IDICES OF HASH TABLE
        // set<int> n1, n2;
	int n = nums1.size();
        int m = nums2.size();
        
        for(int i=0; i<n; i++) {
            n1.insert(nums1[i]);
        }
        for(int i=0; i<m; i++) {
            n2.insert(nums2[i]);
        }
        vector<int> v;
        vector<vector<int>> ans;
        
        for(auto i : n1) {
            if(n2.find(i) == n2.end())
                v.push_back(i);
        }
        
        ans.push_back(v);
	v.clear();
       
	for(int i : n2){
            if(n1.find(i) == n1.end())
                v.push_back(i);
        }
        
        ans.push_back(v);
        return ans;
    }
};




