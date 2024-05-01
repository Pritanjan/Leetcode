// A 1 

class Solution {
public:
    string reversePrefix(string word, char ch) {        
        int p = word.find(ch);            
        reverse(word.begin(), word.begin() + p+1);
        return word;
    }
};





// A 2

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size(); i++){
            if(word[i] == ch){
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }        
        return word;
    }
};


