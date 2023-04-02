// 🙏🙏 JAI HANUMAN 🙏🙏

// APPROACH 1 [ BRUTE FORCE -- TLE ]
class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        vector<int> res(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // if(spells[i] * potions[j] >= success) {  --> RTE
                if((long long)spells[i] * (long long)potions[j] >= success) {
                    res[i]++;
                }
            }
        }
        return res;
    }
};




// APPROACH 2

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> v(spells.size());
        
        for(int i=0; i<spells.size(); i++) {
            int L = 0;
            int R = potions.size()-1;
            int mid;
            
            while(L <= R) {
                mid = L + (R - L)/2;
                if((long long int)spells[i] * (long long int)potions[mid] >= success) R = mid - 1;
                else L = mid + 1;
            }
            v[i] = potions.size()-R-1;
        }
        return v;
    }
};



// OR

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(), potions.end());
        vector<int> res(n, 0);
        int j = m - 1;
        for(int i=0; i<n; i++) {
            while(j >= 0 && (long long)spells[i] * (long long)potions[j] < success) {
                j--;
            }
            res[i] = j + 1;
        }
        return res;
    }
};




// APPROACH 3

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        for (auto &x : spells)
            x = potions.end() - upper_bound(potions.begin(), potions.end(), (success - 1) / x);
        return spells;
    }
};




