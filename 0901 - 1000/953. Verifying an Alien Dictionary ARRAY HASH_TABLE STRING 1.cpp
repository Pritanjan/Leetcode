//https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100

// APPROACH 1 (mapping Letters of Alien order to english order)

// Mapping the letters in order to equivalent words considering normal english ordering, 
// transform word and thencheck whether they are sorted are not by using is sorted  
// function from c++ STL.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char,char> ump;
        for(int i=0; i<order.size(); i++)
            ump[order[i]] = i + 'a';
        // Infact, we can do without the + 'a' below as well. It just won't map to English but rather to characters having ascii 0,1,2...
        
        for(auto& i : words)
            for(auto& j : i )
                j = ump[j];
        
        return is_sorted(words.begin(),words.end());
    }
};

// Time Complexity : O(N), 
// where N is the total number of characters in words.
// Space Complexity : O(1), 
// we only need constant amount of space to store the mapping of letters to index which
// does not depend on the size of input. Hence we get constant space complexity.




class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for(int i=0; i<26; i++){
            mapping[order[i] - 'a'] = i; 
        }
        
        for(string &s : words){
            for(char &c : s)
                c = mapping[c - 'a'];
        }
        return is_sorted(words.begin(),words.end());
    }
};


// APPROACH 2

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i=1; i < words.size(); i++) {
            if (!Ordered(words[i-1], words[i], order)) {
                return false;
            }
        }
        return true;
    }

    bool Ordered(string prev, string curr, string order) {
        int pP = 0;
        int cP = 0;

        while(pP < prev.length() && cP < curr.length() && prev[pP] == curr[cP]) {
            pP++;
            cP++;
        }

        if(pP == prev.length() || cP == curr.length()) {
            if (pP == prev.length()) {
                return true;
            }
            return false;
        }
        return prevCharIsBefore(prev[pP], curr[cP], order);
    }

    bool prevCharIsBefore(char prev, char curr, string order) {
        for (int i = 0; i < 26; i++) {
            if (order[i] == prev) return true;
            if (order[i] == curr) return false;
        }
        return true;
    }
};




// bool isAlienSorted(vector<string>& words, string order): This function takes as input
// a list of words words and an order string order. It iterates over the words list and 
// for each adjacent pair of words, it checks if they are sorted in the given order by 
// calling the isOrdered function. If all the adjacent words are sorted, it returns true.
// If any pair of adjacent words are not sorted, it returns false.

// bool isOrdered(string prev, string curr, string order): This function takes as input two 
// strings prev and curr and an order string order. It compares each character of the two
// strings and returns true if the prev string is before the curr string in the given order, 
// and false otherwise. If both strings have the same characters in the common prefix, the 
// function returns true if the prev string is shorter, and false if the curr string is shorter.

// bool prevCharIsBefore(char prev, char curr, string order): This function takes as input 
// two characters prev and curr and an order string order. It iterates over the order string 
// and returns true if the prev character appears before the curr character in the order
// string, and false otherwise.

