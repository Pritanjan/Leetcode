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






// A 2

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






// A 3 

