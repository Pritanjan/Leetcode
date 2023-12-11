// A 1 - using Hash map

class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnts;
        int tgt = n/4;
        for(auto num : nums) {
            cnts[num]++;

            if(cnts[num] > tgt) return num;
        }
        return 0;
    }
};


