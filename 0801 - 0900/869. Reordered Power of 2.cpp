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
        string s = to_string(n);
        
        // Generate powers of two up to 10^9 (2^29)
        vector<string> v;
        for(int i=0; i<30; i++) {
            v.push_back(to_string(1 << i));
        }
        
        // Count the frequency of each digit in n
        unordered_map<char, int> cnt;
        for (char digit : s) {
            cnt[digit]++;
        }
        
        // Check if any power of two has the same digit frequencies
        for(const string& it : v) {
            if(it.size() == s.size()) {
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


// 1. Convert the given integer n into a string to manipulate its digits.
// 2. Generate a list of all the powers of two that can be represented as strings 
//    (up to a certain limit, let's say 10^9, which is 2^29).
// 3. For each power of two string, check if it's possible to reorder the digits of the input string
//    to match the power of two string. To do this, compare the frequency of each digit in both strings.
// 4. If you find a match, return true; otherwise, return false after checking all powers of two.






// A 3

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Convert n to a string
        string s = to_string(n);
        int size = s.length();
        
        // Generate powers of two up to 10^9 (2^29)
        vector<string> v;
        for(int i=0; i<30; i++) {
            int pow = 1 << i;
            if(to_string(pow).length() == size) {
                v.push_back(to_string(pow));
            }
        }
        
        // Generate all permutations of the digits of str_n
        sort(s.begin(), s.end());
        do {
            // Check if the permutation matches any power of two
            if(s[0] != '0' && binary_search(v.begin(), v.end(), s)) {
                return true;
            }
        } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};





// A 4

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Count the frequency of each digit in n
        vector<int> v(10, 0);
        while(n > 0) {
            v[n % 10]++;
            n /= 10;
        }
        
        // Check if any power of two has the same digit frequencies
        for(int i=1; i<=1e9; i *= 2) {
            vector<int> v1(10, 0);   // store power cnt
            int temp = i;
            while(temp > 0) {
                v1[temp % 10]++;
                temp /= 10;
            }
            if(v == v1) return true;
        }        
        return false;
    }
};






// A 5

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt = cntDigits(n);
        for(int i=0; i<31; i++) {
            if(cnt == cntDigits(1 << i)) {
                return true;
            }
        }
        return false;
    }
private:
    vector<int> cntDigits(int num) {
        vector<int> cnt(10, 0);
        while(num > 0) {
            cnt[num % 10]++;
            num /= 10;
        }
        return cnt;
    }
};


