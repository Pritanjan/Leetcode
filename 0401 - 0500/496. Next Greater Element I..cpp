// NEXT SMALL ELEMENT
// https://github.com/Pritanjan/time-pass/blob/main/Stack/7%20Next%20Smaller%20Element.cpp



// NEXT GREATER ELEMENT
// A 1

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        for(int i=0; i<nums1.size(); i++){
            int p = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() ;
            for(int j=p+1; j<nums2.size(); j++){
                if(nums1[i] < nums2[j]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};


// OR


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int num1 : nums1) {
            bool found = false;
            int next = -1;
            for(int num2 : nums2) {
                if(found && num2 > num1) {
                    next = num2;
                    break;
                }
                if(num2 == num1) found = true;
            }
            res.push_back(next);
        }
        return res;
    }
};






// A 2

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1); // Initialize ans array with -1
        stack<int> st; // Stack to store the elements of nums2
        unordered_map<int, int> mp; // Map to store the next greater element of each element of nums2

        // Traverse nums2 in reverse order
        for(int i=nums2.size() - 1; i>=0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop(); // Pop the elements from the stack if they are smaller or equal to nums2[i]
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top(); // Store the next greater element of nums2[i] in the map
            st.push(nums2[i]); // Push nums2[i] into the stack
        }
        // Traverse nums1 to find the corresponding next greater elements
        for (int i=0; i<nums1.size(); i++) {
            ans[i] = mp[nums1[i]]; // Assign the next greater element of nums1[i] to ans[i]
        }
        return ans;
    }
};

// T.C. --> O(n), where n is the size of nums2, as we traverse the array only once. 
// S.C. --> O(n), as we use a stack and a map to store the elements and their next greater elements






// A 3
