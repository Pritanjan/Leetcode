//https://leetcode.com/problems/search-suggestions-system/

//Intuition

//Since the question asks for the result in a sorted order, let's start with sorting products. An advantage that comes with sorting is Binary Search, we can binary search for the prefix. Once we locate the first match of prefix, all we need to do is to add the next 3 words into the result (if there are any), since we sorted the words beforehand.

//Algorithm

//Sort the input products.
//Iterate each character of the searchWord adding it to the prefix to search for.
//After adding the current character to the prefix binary search for the prefix in the input.
//Add next 3 strings from the current binary search start index till the prefix remains same.
//Another optimization that can be done is reducing the binary search space to current start index (This is due to the fact that adding more characters to the prefix will make the next search result's index be at least > current search's index).



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        int n = p.size();
        sort(p.begin(), p.end());
        vector<vector<string>> ans;
        int start, L=0;
        string prefix;
        for(char &c : s){
            prefix += c;
            
            // Get the starting index of word starting with `prefix`
            start = lower_bound(p.begin()+L, p.end(), prefix) - p.begin();
            
            // Add empty vector to result
            ans.push_back({});
            
            // Add the words with the same prefix to the result.
            // Loop runs until `i` reaches the end of input or 3 times or till the
            // prefix is same for `products[i]` Whichever comes first.
            for(int i=start; i<min(start + 3, n) && !p[i].compare(0, prefix.length(), prefix); i++)
                ans.back().push_back(p[i]);
            
            // Reduce the size of elements to binary search on since we know
            // L = start;
        }
        
        return ans;
    }
};

// T.C. --> O(n log(n)) + O(m log(n)) 
// n = p.size()
// m = s.size()

// O(n log(n)) --> because of sorting 
// O(m log(n)) --> because of binary_search 



