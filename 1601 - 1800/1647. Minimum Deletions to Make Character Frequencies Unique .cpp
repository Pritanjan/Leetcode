// A 1 USing Hash Map

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {};
        int ans = 0;       
        unordered_map<int, bool> map;
        for(char i : s) freq[i - 'a']++;
        
        for(int i=0; i<26; i++) {
            // int it = freq[i];
            while(freq[i] > 0 && map[freq[i]] > 0) {
                ans++;
                map[freq[i]];
                freq[i]--;
            }
            map[freq[i]] = true;
        }
        return ans;
        
    }
};


// OR 2 map


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMp;
        // Count the frequency of each character in the string.
        for(char c : s) freqMp[c]++;
        
        unordered_map<int, int> cntMp; // Maps frequency to count of characters with that frequency
        int minDel = 0;
        for(auto& it : freqMp) {
            int tmp = it.second;
            
            // Increase the frequency until it's unique or 0.
            while(cntMp[tmp] > 0) {
                tmp--;
                minDel++;
            }
            if(tmp > 0) cntMp[tmp] = 1;
        }        
        return minDel;
    }
};


// OR


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMp;
        for(char c : s) freqMp[c]++;
        
        unordered_map<int, int> freq;
        int minDel = 0;
        for(auto& it : freqMp) {
            int tmp = it.second;
            while(freq.count(tmp) > 0) {
                tmp--;
                minDel++;
            }
            if(tmp > 0) freq[tmp] = 1;
        }        
        return minDel;
    }
};






// A 2  - USing Hash Set

// Greedy works since we can only delete characters (we cannot add or replace characters).
// So, count each character first. For each 26 characters, check if it's count is already used. 
// If so, delete characters until you find unused count, or reach zero.

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {};
        int ans = 0;        
        unordered_set<int> set;
        for(char i : s) freq[i - 'a']++;        
        for(int i=0; i<26; i++){
            for(;freq[i] > 0  && !set.insert(freq[i]).second; freq[i]--)  ans++;
        }
        return ans;
    }
};


// Time: O(n); note that the second loop will not have more than 26 * 26 total operations.
// Memory: O(1) as we will not store more than 26 different frequencies.





// A 3 - using an Array to Count Frequencies (same as A1 b)

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        
        // vector<int> cnt(1001, 0);
        vector<int> cnt(s.size()+1, 0);
        int minDel = 0;

        for(int i=0; i<26; i++) {
            int tmp = freq[i];
            if(tmp > 0) {
                while(cnt[tmp] > 0) {
                    tmp--;
                    minDel++;
                }
                if(tmp > 0) cnt[tmp] = 1;
            }
        }        
        return minDel;
    }
};





// A 4

