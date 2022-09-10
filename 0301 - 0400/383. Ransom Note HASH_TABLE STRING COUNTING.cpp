//https://leetcode.com/problems/ransom-note/

//As we're just dealing with lowercase English letters, we just need an array of length 26 to store the frequency of the letters.

class Solution {
public:
    bool canConstruct(string s1, string s2) {
 		// you can also use unordered_map<int, int> m; here
		// since we're just dealing with lowercase English letters, 
        // we can just use an array of length 26 to store the frequency of them00
        int count[26] = {0};
        // count each character
        for(char i : s2){
            count[i - 'a']++;
        }
        // check if it can be found in m and substract by 
        for(char i : s1){
        	// if it is less than 0, it means it cannot be constructed from magazine
            if(count[i - 'a']-- <= 0)
                return false;
        }
        return true;
    }
};

// T.C. O(n)

class Solution {
public:
    bool canConstruct(string s1, string s2) {
        // vector<int> v(26,0);
        // unordered_map <char, int> um(26);
        int count[26] = {0};
        
        for(int i=0; i<s2.size(); i++){
            // um[s2[i]]++;
            count[s2[i] - 'a']++;
        }
        
        for(int i=0; i<s1.size(); i++){
            // if(--um[s1[i]] < 0)
            if(count[s1[i] - 'a']-- <= 0)
                
                return false;
        }
        return true;
    }
};

// T.C. O(n)


class Solution {
public:
    bool canConstruct(string s1, string s2) {
        // vector<int> v(26,0);
        unordered_map <char, int> um(26);
        
        for(int i=0; i<s2.size(); i++){
            um[s2[i]]++;
        }
        
        for(int i=0; i<s1.size(); i++){
            if(--um[s1[i]] < 0)
                return false;
        }
        return true;
    }
};



class Solution {
public:
    bool canConstruct(string s1, string s2) {
        vector<int> v(26,0);
        
        for(int i=0; i<s2.size(); i++){
            v[s2[i] - 'a']++;
        }
        
        for(int i=0; i<s1.size(); i++){
            if(--v[s1[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
