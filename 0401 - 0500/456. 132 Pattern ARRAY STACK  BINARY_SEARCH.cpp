//https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int sec = -2147483648;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] < sec)
                return true;
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
// the biggest num will always stay in the stack and second one will stay on my second int ,if I can find nums[i] smaller than second than I can return true because I am searching from right to left :)

