// Similar question LC 169

// APPROACH 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> um;
        // map<int, int> um;  //BOTH WORKS
        for(auto i : nums) um[i]++;
        
        for(auto it : um)
            if(it.second > n/3) {
                v.push_back(it.first);
            }
        return v;
    }
};





// APPROACH 2

