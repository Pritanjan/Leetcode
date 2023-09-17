// A 1

class Solution {
public:
    string sortString(int n){
        // since the input is an integer,
        // we convert it to a string first
        string s = to_string(n);
        // sort the string
        sort(s.begin(), s.end());
        // return the string
        return s;
    }
    
    // the idea is to sort `n` and compare all sorted power of two
    // if they are matched, then it means they can be reordered to each other
    bool reorderedPowerOf2(int n) {
        // since the sorted string of n is always same
        // so we convert it here instead of doing it in the loop
        string s = sortString(n);
        for (int i = 0; i < 30; i++) {
            // power of 2 = 1 << i
            // we sort each power of 2 string
            string t = sortString(1 << i);
            // and compare with `s`
            // if they are matched, then return true
            if (s == t) return true;
        }
        // otherwise it is not possible to reorder to a power of 2
        return false;
    }
};






// A 2

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Convert n to a string
        string str_n = to_string(n);
        
        // Generate powers of two up to 10^9 (2^29)
        vector<string> v;
        for(int i=0; i<30; i++) {
            v.push_back(to_string(1 << i));
        }
        
        // Count the frequency of each digit in n
        unordered_map<char, int> cnt;
        for (char digit : str_n) {
            cnt[digit]++;
        }
        
        // Check if any power of two has the same digit frequencies
        for(const string& it : v) {
            if(it.size() == str_n.size()) {
                unordered_map<char, int> cnt1;
                for(char digit : it) {
                    cnt1[digit]++;
                }
                if(cnt == cnt1) return true;
            }
        }        
        return false;
    }
};






// A 3
