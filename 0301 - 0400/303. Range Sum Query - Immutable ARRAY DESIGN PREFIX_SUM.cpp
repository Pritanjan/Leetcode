//https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> v;
    
    NumArray(vector<int>& nums) {
        v.push_back(0);
        for(auto i : nums){
            v.push_back(v.back() + i);
        }
    }
    
    int sumRange(int L, int R) {
        return v[R+1] - v[L];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
