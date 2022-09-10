// https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        
        for(int i : arr){
            if(s.count(2*i) || !(i % 2) && s.count(i/2))
                return true;
            s.insert(i);
        }
        return false;
    }
};
