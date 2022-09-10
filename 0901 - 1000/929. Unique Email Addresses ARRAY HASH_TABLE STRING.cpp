//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for(auto& s : emails){
            auto fin  = find(s.begin(), s.end(), '@');
            auto del  = remove(s.begin(), fin, '.');
            auto plus = find(s.begin(), del, '+');
            s.erase(plus, fin);
        }
        return unordered_set(emails.begin(), emails.end()).size();   
    }
};

//The solution uses remove and erase functions from STL.
//Remove function removes elements matching to the passed value.
//(NOTE :- It does not actually erase them, it just moves them to the front and returns iterator to the new ending after removing.
//You should not erase them instantly as it will invalidate the previously stored iterators.
//After you are done moving the important information to the front, you can erase what is not necessary ( which in this case is everything from '+' to just before '@' )
//Instead of pushing the new string every time in the set, we use the range constructor of set (or unordered_set).
