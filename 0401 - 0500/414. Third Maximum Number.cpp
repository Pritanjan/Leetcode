// https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int > s;
        for(int &p : nums)
            s.insert(p);
        
        // if(s.size()<3)
        //     return *max_element(s.begin(), s.end());
        // else
        //     *next(s.begin(), s.size()-3);
         return s.size()<3 ? *max_element(s.begin(),s.end()) : *next(s.begin(), s.size() - 3);
    }
};
