class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> MorseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
   
        
        unordered_set<string> MorseWord;
//        set<string> MorseWord;
        
		for(auto word : words){
            string morse = "";
            
            for(auto ch : word)
                morse += MorseCode[ch - 'a'];
            MorseWord.insert(morse);
        }
        return MorseWord.size();
 
    }
};




