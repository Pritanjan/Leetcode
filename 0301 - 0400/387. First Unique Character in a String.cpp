// https://practice.geeksforgeeks.org/problems/find-first-repeated-character4108/1
// Find first repeated character

string firstRepChar(string s) {
    unordered_map<char, int> ump;
    string ans = "";
    for(int i=0; i<s.size(); i++) {
        ump[s[i]]++;
        if(ump[s[i]] == 2) {
            ans = s[i];
            return ans;
        }
    }
    return "-1";
}






// A 1 - Brute force 
// Traverse string s 2 times. 
// 1st traversal, store counts of every character into the hash table,
// 2nd traversal, find the first character that appears only once.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int> um;
        for(char& ch : s ) {
            um[ch]++;
        }        
        for(auto& i : s) {
            if(um[i] == 1) return i;
        }
        return -1;
    }
};






// A 2

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        for(char i='a'; i<='z'; i++){
            int j = s.find(i);
            if(j != -1 and j == s.find_last_of(i)) ans = min(ans,j);
        }        
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};






// A  3

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
	for(char c : s)  v[c - 'a']++;
	for(int i = 0; i < s.length(); i++) {
	    if(v[s[i] - 'a'] == 1)  return i;
	}
	return -1;
    }
};






// A 4

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0; i<s.size(); i++) {
            if(s.find(s[i], s.find(s[i]) + 1) == string::npos) return i;
        }
        return -1;
    }  
};






// A 5


