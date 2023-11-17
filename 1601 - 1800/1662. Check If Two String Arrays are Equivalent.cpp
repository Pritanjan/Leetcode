// A 1 

class Solution {
public:
    string Concatenate(vector<string> &word){
        // string s = "";
        // for(auto i : word) s += i;
        // return s;

        return accumulate(word.begin(), word.end(), string());
    }    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = Concatenate(word1);
        string s2 = Concatenate(word2);        
        
        // return !s1.compare(s2) ? true : false;
        return s1 == s2;
    }
};


// OR

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        auto concat = [](vector<string>& words) {
            return accumulate(words.begin(), words.end(), string{});
        };
        return concat(word1) == concat(word2);
            
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






// A 4 - Concatenate and Compare USing STL

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return accumulate(word1.begin(), word1.end(), string()) == accumulate(word2.begin(), word2.end(), string());
        return accumulate(word1.begin(), word1.end(), string{}) == accumulate(word2.begin(), word2.end(), string{});
    }
};






// A 5 - Using stringstream

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        ostringstream oss1, oss2;
        copy(word1.begin(), word1.end(), ostream_iterator<string>(oss1));
        copy(word2.begin(), word2.end(), ostream_iterator<string>(oss2));
        return oss1.str() == oss2.str();        
    }
};






// A 6 


