class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string vowels = "aeiou";
        int numVowels = 5;
    
        int count = 0;
        for(int i = left; i <= right; i++) {
            int n = words[i].size();
            if(vowels.find(words[i].front()) != string::npos && vowels.find(words[i].back()) != string::npos) {
                count++;
            }
            else if(n > 1 && vowels.find(words[i].front()) != string::npos && vowels.find(words[i][1]) != string::npos && vowels.find(words[i].back()) != string::npos && vowels.find(words[i][n-2]) != string::npos) {
                count++;
            }
            else if(n > 2 && vowels.find(words[i].front()) != string::npos && vowels.find(words[i][1]) != string::npos && vowels.find(words[i][2]) != string::npos && vowels.find(words[i].back()) != string::npos) {
                count++;
            }
        }   
        return count;
    }
};



