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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;

        // Create a vector to store the next greater elements for nums2
        vector<int> v(nums2.size(), -1);
        for(int i=0; i<nums2.size(); ++i) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                v[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for(int num : nums1) {
            int idx = -1;
            for(int i=0; i<nums2.size(); ++i) {
                if(nums2[i] == num) {
                    idx = i;
                    break;
                }
            }
            if(idx != -1) res.push_back(v[idx]);
            else res.push_back(-1);
        }
        return res;        
    }
};






// A 4

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        deque<int> dq;

        // Find next greater elements and store them in the map
        for(int num : nums2) {
            while(!dq.empty() && num > dq.back()) {
                mp[dq.back()] = num;
                dq.pop_back();
            }
            dq.push_back(num);
        }

        // Populate the result vector for nums1
        for(int num : nums1) {
            if(mp.find(num) != mp.end()) res.push_back(mp[num]);
            else res.push_back(-1);
        }
        return res;
    }
};





// A 5

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        priority_queue<pair<int, int>> pq;  // maxHeap
        unordered_map<int, int> mp;  // to store next next Greater element

        // Find next greater elements for nums2
        for(int i=0; i<nums2.size(); ++i) {
            while(!pq.empty() && nums2[i] > -pq.top().first) {
                mp[-pq.top().first] = nums2[i];
                pq.pop();
            }
            pq.push({-nums2[i], i});
        }

        // Populate the result vector for nums1 using the nextGreater map
        for(int i=0; i<nums1.size(); ++i) {
            if(mp.find(nums1[i]) != mp.end()) {
                res[i] = mp[nums1[i]];
            }
        }
        return res;
    }
};






// A 6
