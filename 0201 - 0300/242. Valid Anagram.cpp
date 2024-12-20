// A 1

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());        
        for(int i=0; i<s2.size(); i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
};






// A 2
// Sort the characters of both strings and compare the sorted strings

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};






// A 3 - Unordered map
// This idea uses a hash table to record the times of appearances of each letter in 2 strings s and t. 
// For each letter in s, it increases the counter by 1 
// while for each letter in t, it decreases the counter by 1. 
// Finally, all the counters will be 0 if they two are anagrams of each other.

// problem statement says that "the string contains only lowercase alphabets", 
// we can simply use an array to simulate the unordered_map and speed up the code

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        unordered_map <char, int> ump;
        for(int i=0; i<s1.size(); i++) {
            ump[s1[i]]++;
            ump[s2[i]]--;
        }        
        for(auto i : ump) {
            if(i.second) return false;
        }
        return true;
    }
};


// OR


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> ump; // charracter count

        // Count the frequency of characters in string s
        for(char c : s) ump[c]++;
        
        // Decrement the frequency of characters in string t
        for(char c : t) {
            if(ump.find(c) == ump.end() || ump[c] <= 0) return false;
            ump[c]--;
        }
        // Check if all character counts are zero
        for(auto& i : ump) {
            if(i.second != 0) return false;
        }
        return true;
    }
};






// A 4 [ Character Counting using Arrays ]
// Count the frequency of characters in both strings using arrays.
// Compare the character counts.

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        int um[26] = {0};
        for(int i=0; i<s1.size(); i++){
            um[s1[i] - 'a']++;
            um[s2[i] - 'a']--;
        }        
        for(int i=0; i<26; i++){
            if(um[i]) return false;
        }
        return true;
    }
};


// OR


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int arr[26] = {0};   // Count array for characters
        for(char c : s) arr[c - 'a']++;
        for(char c : t) {
            arr[c - 'a']--;
            if(arr[c - 'a'] < 0) return false;
        }
        // return true;
        
        // Check if all character counts are zero
        return all_of(arr, arr+26, [](int count) { return count == 0; });
    }
};


// OR


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> freq(256, 0);
        for(char c : s) freq[c]++;
        for(char c : t) freq[c]--;
        for(int f : freq) {
            if(f != 0) return false;
        }
        return true;
    }
};






// A 5  -  Using Multiset

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_multiset<char> ust;
        for(char c : s) ust.insert(c);
        for(char c : t) {
            auto it = ust.find(c);
            if(it == ust.end()) return false;
            ust.erase(it);
        }
        return ust.empty();
    }
};






// A 6





// [ Anagram Signature ] WRONG
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSum = 0, tSum = 0;
        for(char c : s) sSum += c;
        for(char c : t) tSum += c;
        return sSum == tSum;
    }
};





// java 
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freq1 = getFrequencyArray(s);
        int[] freq2 = getFrequencyArray(t);        
        for (int i = 0; i < freq1.length; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

    public static int[] getFrequencyArray(String s1) {
        int[] freq = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            char ch = s1.charAt(i);
            if (ch >= 65 && ch <= 90)
                freq[ch - 65]++;
            else if (ch >= 97 && ch <= 122)
                freq[ch - 97]++;
        }
        return freq;
    }
}

//  Prime Number Multiplication: WRONG
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unsigned long long sPdt = 1, tPdt = 1;

        for(char c : s) sPdt *= primes[c - 'a'];
        for(char c : t) tPdt *= primes[c - 'a'];

        return sPdt == tPdt;
    }
};






