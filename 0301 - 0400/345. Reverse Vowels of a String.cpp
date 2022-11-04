// https://leetcode.com/problems/reverse-vowels-of-a-string/

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
