

//We can observe that we only need to verify if all possible codes of length k exists in the string s. Instead of generating all the codes and then checking if each one exists in s, we can just check all the substrings of length k in the string s. If number of all the distinct substrings of length k is 2^k, we are sure that all binary codes exists in the given string. We can use a hashset to keep track of all distinct substrings found.

class Solution {
public:
    bool hasAllCodes(string str, int k) {
        
        int n = str.size();
        unordered_set<string> us;
        for(int i=0; i<n-k+1; i++){
            us.insert(str.substr(i,k));
        }
//        if(us.size() == pow(2,k))
//            return true;
//        return false;

// if number of distinct substrings in str equals 2^k (1 << k), return true
	return us.size() == (1 << k);
    }
};

//Time Complexity : O(N*k), where N is the size of string and k is length of binary code.
//Space Complexity : O(N*k)

