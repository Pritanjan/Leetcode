class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length())
            swap(str1, str2);
        if (str1 == str2)
            return str1;
        if (str1.substr(0, str2.length()) != str2)
            return "";
        return gcdOfStrings(str1.substr(str2.length()), str2);
    }
};



// 1. If the length of str1 is less than the length of str2, the two strings are swapped.
// 2. If str1 is equal to str2, the function returns str1 as the GCD of the two equal strings.
// 3. If the first str2.length() characters of str1 are not equal to str2, the function returns an empty 
//    string, indicating that the two strings have no common divisor.
// 4. If the previous conditions are not met, the function returns the GCD of str1 minus the first
//    str2.length() characters and str2. This is achieved by recursively calling the gcdOfStrings
//    function with str1.substr(str2.length()) and str2 as inputs.



