// A 1 

class Solution {
public:
    string Concatenate(vector<string> &v){
        string s = "";
        for(auto i : v){
            s += i;
        }
        return s;
    }    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = Concatenate(word1);
        string s2 = Concatenate(word2);        
        return !s1.compare(s2) ? true : false;
    }
};






// A 2 - Concatenate and Compare

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        for(string s : word1) {
            s1 += s;
        }
        string s2;
        for(string s : word2) {
            s2 += s;
        }
        return s1 == s2;
    }
};

// T.C. --> O(N*K)
// S.C. --> O(N*K)





// A 3 - 2 Pointer

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ptr1w = 0, ptr2w = 0;
        int ptr1s = 0, ptr2s = 0;
        while(ptr1w < word1.size() && ptr2w < word2.size()) {
            if(word1[ptr1w][ptr1s++] != word2[ptr2w][ptr2s++]) {
                return false;
            }            
            if(ptr1s == word1[ptr1w].size()) {
                ptr1w++;
                ptr1s = 0;
            }            
            if(ptr2s == word2[ptr2w].size()) {
                ptr2w++;
                ptr2s = 0;
            }
        }
        return ptr1w == word1.size() && ptr2w == word2.size();
    }
};

// T.C. --> O(N*K)
// S.C. --> O(1)






// A 4 

