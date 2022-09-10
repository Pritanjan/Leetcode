// https://leetcode.com/problems/reverse-vowels-of-a-string/

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
