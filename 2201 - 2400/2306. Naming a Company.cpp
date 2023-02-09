// APPROACH 1


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> ump[26];
        
        // Add the suffix of each string from our parameter ideas to begCharToSuffix
        for(auto& id : ideas){
            ump[id[0] - 'a'].insert(id.substr(1));
        }
        
        long long res = 0;
        // Iterate through all of thee characters and count the number of equal suffix values
        for(int i=0; i<25; i++){
            for(int j=i+1; j<26; j++){
                int temp = 0;
                for(auto& idA : ump[i]){
                    if(ump[j].count(idA)){
                        temp++;
                    }
                }
                
                // Since we know that two words are unique if they don't make a word that was already in
                // the array, we remove the mutual suffixes that two different characters share. Then, 
                // after doing this, we know that we can multiply our result by two since the remaining 
                // suffixes (+ their original prefix letter) don't exist in the original array which 
                // means that we can use both of them in either position.
                // Eg. if "coffee" and "donuts" are both unique, we could include "coffee donuts" and 
                // "donuts coffee" in our answer.
                res += 2 * (ump[i].size() - temp) * (ump[j].size() - temp) ; 
            }
        }
        
        return res;
    }
};


// TIME COMPLEXITY: O(m * n), where m is the average length of a string and n is the number of strings.
// With constants, time complexity would be (26 * 25 / 2 * m * n)
// SPACE COMPLEXITY: O(m * n), where m is the average length of a string and n is the number of strings.




// APPROACH 2


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> ump(ideas.begin(), ideas.end());
        vector<vector<int>> cur(128, vector<int>(128,0));
        
        long long ans = 0;
        for (string& s : ideas) {
            for (char c='a'; c<='z'; c++){
                string word = s;
                word[0] = c;
                if (ump.find(word) == ump.end()){
                    ans += cur[s[0]][c];
                    cur[c][s[0]]++;
                }
            }
        }
        return ans * 2;
    }
};
