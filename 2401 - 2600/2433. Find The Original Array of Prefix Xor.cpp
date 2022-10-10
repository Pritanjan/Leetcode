// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> v;
        v.push_back(pref[0]);
        
        for(int i=0; i<pref.size()-1; i++){
            v.push_back(pref[i] ^ pref[i+1]);
        }
        
        return v;
    }
};

// a ^ b = c
// b ^ c = a
// c ^ a = b





