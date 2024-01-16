// A 1

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0; i<n; i ++) mp[arr[i]]++;
        
        // set<int> unq;
        // for(auto [first, second] : mp){
        //     unq.insert(second);
        // }    
        // return unq.size() == mp.size();

        n = 0;
        for(auto &m : mp){
            n++;
            uq.insert(m.second);
        }        
        return n == st.size();
    }
};






// A 2

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        unordered_set<int> occ;

        // Count the occurrences of each value in the array
        for(int num : arr) cnt[num]++;
        
        // Check if the number of occurrences is unique
        for(auto& p : cnt) {
            if(!occ.insert(p.second).second) {
                return false;
            }
        }
        return true;
    }
};






// A 3 - STL

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> occ;

        transform(arr.begin(), arr.end(), inserter(occ, occ.begin()),
                    [&arr](int val) { return count(arr.begin(), arr.end(), val); });
                    
        return occ.size() == unordered_set<int>(arr.begin(), arr.end()).size();
    }
};






// A 4 

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int maxSize = 2001;
        array<int, maxSize>  freq{};
        
        for(auto num : arr) {
            freq[num + 1000]++;
        }

        unordered_set<int> occ;
        for(auto f : freq) {
            if(f > 0 and !occ.insert(f).second) return false;
        }
        return true;
    }
};






// A 5 

