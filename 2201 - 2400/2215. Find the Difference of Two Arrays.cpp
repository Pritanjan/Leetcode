// A 1

class Solution {
public: 
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa(begin(A), end(A)), sb(begin(B), end(B));
        vector<vector<int>> ans(2);
	    
        for(int i : sa) if(sb.count(i) == 0) ans[0].push_back(i);
        for(int i : sb) if(sa.count(i == 0) ans[1].push_back(i);        
        return ans;
    }
};






// A 2 [ MAP ]

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {		
        map<int, int> m1, m2;
        int n = nums1.size();
        int m = nums2.size();
        
        for(auto i : nums1) m1[i]++;
        for(auto i : nums2) m2[i]++;
                
        vector<int> v;
        vector<vector<int>> ans;
        for(auto it : m1) {
            if(m2.find(it.first) == m2.end())
                v.push_back(it.first);
        }
        
        ans.push_back(v);
        v.clear();       
        for(auto it : m2) {
            if(m1.find(it.first) == m1.end())
                v.push_back(it.first);
        }        
        ans.push_back(v);
        return ans;
    }
};





// A 3 [ SET ]

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





 
// A 4
		
// To do this, we first create two unordered sets set1 and set2 containing the integers in 
// nums1 and nums2, respectively
// We then loop through the elements in nums1 and check if they are not in set2. If so, 
// we add them to answer[0]. Similarly, we loop through the elements in nums2 and
// check if they are not in set1. If so, we add them to answer[1].

// sort function is used to sort nums1 and nums2, and then unique is used to remove the duplicates. 
			   
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {            
        vector<vector<int>> answer(2);
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Remove duplicates in nums1 and nums2
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        for(int num : nums1) {
            if(set2.count(num) == 0) {
                answer[0].push_back(num);
            }
        }

        for(int num : nums2) {
            if(set1.count(num) == 0) {
                answer[1].push_back(num);
            }
        }

        return answer;
    }
};


			   
			   
			   

// A 5 

class Solution {
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            bool existInNums2 = false;
            // Check if num is present in the second arg nums2.
            for (int x : nums2) {
                if (x == num) {
                    existInNums2 = true;
                    break;
                }
            }
            
            if (!existInNums2) {
                onlyInNums1.insert(num);
            }
        }
        
        // Convert to vector.
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};
