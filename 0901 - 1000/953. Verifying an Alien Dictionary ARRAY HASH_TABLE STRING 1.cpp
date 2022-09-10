//https://leetcode.com/problems/verifying-an-alien-dictionary/

//APPROACH (mapping Letters of Alien order to englishorder)

//Mapping the letters in order to equivalent words considering normal english ordering, transform word and thencheck whether they are sorted are not by using is sorted function from c++ STL.

//https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char,char> ump;
        for(int i=0; i<order.size(); i++)
            ump[order[i]] = i + 'a';
        // Infact, we can do without the + 'a' below as well. It just won't map to English but rather to characters having ascii 0,1,2...
        
        for(auto& i : words)
            for(auto& j : i )
                j = ump[j];
        
        return is_sorted(words.begin(),words.end());
    }
};

//Time Complexity : O(N), where N is the total number of characters in words.
//Space Complexity : O(1), we only need constant amount of space to store the mapping of letters to index which does not depend on the size of input. Hence we get constant space complexity.
