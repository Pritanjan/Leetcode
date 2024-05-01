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






// A 3 

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int L = 0;
        for (int R=0; R<word.length(); R++) {
            // We found ch - reverse characters up to ch by swapping
            if (word[R] == ch) {
                while(L <= R) {
                    swap(word[R], word[L]);
                    L++;
                    R--;
                }
                return word;
            }
        }
        return word;
    }
};
