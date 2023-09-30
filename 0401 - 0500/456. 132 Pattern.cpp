// A 0 - Brute Force - TLE

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;

        for(size_t i=0; i<nums.size() - 2; i++) {
            for(size_t j=i+1; j<nums.size() - 1; j++) {
                for(size_t k=j+1; k<nums.size(); k++) {
                    if(nums[k] > nums[i] and nums[j] > nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// T.C. --> O(N ^ 3)
// S.C. --> O(1)


// OR - TLE

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_i = INT_MAX;
        for(int j=0; j<nums.size() - 1; j++) {
            min_i = min(min_i, nums[j]);
            for(int k=j+1; k<nums.size(); k++) {
                if(nums[k] < nums[j] and min_i < nums[k]) {
                    return true;
                }
            }
        }
        return false;
    }
};

// T.C. --> O(N ^ 2)
// S.C. --> O(1)






// A 1

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int sec = -2147483648;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] < sec) return true;
            while(st.size() > 0 && nums[i] > st.top()){
                sec = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// T.C. O(n)
// the biggest num will always stay in the stack and second one will stay on my second int,
// if I can find nums[i] smaller than second than I can return true because
// I am searching from right to left :)


// OR


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int mini[n];
        mini[0] = nums[0];
        for(int i=1; i<n; i++) {
            mini[i] = min(nums[i], mini[i-1]);
        }          
        stack<int> st;
        for(int j=n-1; j>=0; j--){
            while(!st.empty() && st.top() < nums[j]){
                if(st.top() > mini[j]) return true;
                st.pop();
            }
            st.push(nums[j]);
        }
        return false;
    }
};






// A 2 - Using Priority Queue

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        priority_queue<int> pq;  // maxHeap

        int tmp = INT_MIN;
        for(int i=n-1; i>=0; --i) {
            if(nums[i] < tmp) return true;
            while(!pq.empty() && nums[i] > -pq.top()) {
                tmp = -pq.top();
                pq.pop();
            }
            pq.push(-nums[i]);
        }
        return false;
    }
};






// A 3

