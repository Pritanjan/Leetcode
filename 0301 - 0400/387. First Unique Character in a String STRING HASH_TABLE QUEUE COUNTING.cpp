// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int> um;
        
        for(char& ch : s ) {
            um[ch]++;
            // um[s[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(um[s[i]] == 1)
                return i;
        }
        // for(auto& i : s){
        //     if(um[i] == 1)
        //         return i;
        // }
        return -1;
    }
};

//Solution 2
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        for(char i='a'; i<='z'; i++){
            int j = s.find(i);
            if(j != -1 and j == s.find_last_of(i))
                ans = min(ans,j);
        }
        
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};


// SOlution 3
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
		for(char c : s) 
            v[c - 'a']++;
		for(int i = 0; i < s.length(); i++){
			if(v[s[i] - 'a'] == 1) 
                return i;
		}
		return -1;
    }
};
