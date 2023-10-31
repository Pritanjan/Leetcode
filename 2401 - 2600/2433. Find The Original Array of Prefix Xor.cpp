// A 1

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res;
        res.push_back(pref[0]);

        for(int i=1; i<n; i++) {
            res.push_back(pref[i] ^ pref[i-1]);
        }
        return res;
    }
};


// a ^ b = c
// b ^ c = a
// c ^ a = b






// A 2

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        for (int i = n - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        
        return pref;
    }
};



