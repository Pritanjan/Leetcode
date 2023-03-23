// APPROACH 1

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1 ;
        
        while(i < j){
            bool a = false;
            bool b = false;    // TO CHECK WE ARE POINTING TO VOWEL OR NOT
            
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
                a = true ;
            
            if(s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U' || s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' )
                b = true;
            
            if(a && b){ 	   // IF BOTH POINTING TO VOWELS JUST SWAP THEM
                swap(s[j], s[i]);
                i++;
                j--; 
            }
            if(!a)  i++;	// IF i IS NOT POINTING TO VOWEL, MOVE i POINTER FORWARD
            if(!b)  j--;	// IF j IS NOT POINTING TO VOWEL, MOVE j POINTER BACKWARD
        }
        return s;
    }
};






// APPROACH 2

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowel;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            vowel.push_back(i);
        }
        
        int R = vowel.size()-1;
        int L = 0;
        
        while(L < R ){
            // if(s[])
            swap(s[vowel[L]] , s[vowel[R]]);
                L++;
                R--;
        }
        return s;
        
    }
};






// APPROACH 3

class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||  ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j){
            while(i < s.size() and !isVowel(s[i]))
                i++;
            while(j >= 0 and !isVowel(s[j]))
                j--;
            
            if(i < j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

// Time complexity: O(N)
// Space complexity: O(N)










// APPROACH 4

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> ss(s.begin(), s.end());
        vector<char> aeiou = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size(), i = 0, j = n - 1;

        while (i < j) {
            if (find(aeiou.begin(), aeiou.end(), ss[i]) == aeiou.end()) {
                i++;
                continue;
            }
            if (find(aeiou.begin(), aeiou.end(), ss[j]) == aeiou.end()) {
                j--;
                continue;
            }
            if (i < j) {
                swap(ss[i], ss[j]);
            }
            i++;
            j--;
        }
        
        string d = "";
        for (auto c : ss) {
            d += c;
        }
        return d;
    }
};



