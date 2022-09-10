//There is a simpler variation of Approach 1, faster than 100% of submissions without the need for binary search: once you sort the list of products, keep 2 pointers for the begin and end of the list. Then, for each character on searchWord, you can restrict the list of possibilities linearly. This is actually faster than N binary searches on prefixes as you only need to check for the current character.
//
//Illustrating the idea with an example, searching for the word "month":
//
//Initially:
//
//banana <= A
//m
//map
//mobile
//mouse
//zebra <= B
//Index 0, [m]onth:
//
//banana (index 0 != 'm')
//m <= A
//map
//mobile
//mouse <= B
//zebra (index 0 != 'm')
//Index 1, m[o]nth (no need to check for the first "m" again, as it is guaranteed to match from the previous iteration):
//
//banana
//m (length <= 1, so won't have an index 1 to match)
//map (index 1 != 'o')
//mobile <= A
//mouse <= B
//zebra
//Index 2, mo[n]th (as we try to move pointer A, we go past B, meaning that we will no longer have any matches going forward):
//
//banana
//m
//map
//mobile (index 2 != 'n')
//mouse <= B (index 2 != 'n')
//zebra <= A
//As you process each character of searchWord, you will have the possible products between pointers A and B, already sorted lexicographically, so we you simply pick the first 3 starting from A.
//
//Output:
//
//[
//["m", "map", "mobile"], // searching "m"
//["mobile", "mouse"], // searching "mo"
//[], // searching "mon"
//[], // searching "mont"
//[], // searching "month"
//]
//C++ code:
//
//class Solution {
//public:
//    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//        sort(products.begin(), products.end());
//        int a = 0;
//        int b = products.size()-1;
//        
//        vector<vector<string>> result(searchWord.size());
//        for (int i = 0; i < searchWord.size() && a <= b; ++i) {
//            while (
//                a <= b &&
//                // Skip products[a] if index i is not a match
//                (products[a].size() <= i || products[a][i] != searchWord[i])
//            ) {
//                ++a;
//            }
//            while (
//                a <= b &&
//                // Skip products[b] if index i is not a match
//                (products[b].size() <= i || products[b][i] != searchWord[i])
//            ) {
//                --b;
//            }
//            
//            // Pick the first 3 starting from a,
//            // but not going over b
//            for (int k = a; k <= b && k < a+3; ++k) {
//                result[i].push_back(products[k]);
//            }
//        }
//        return result;
//    }
//};
