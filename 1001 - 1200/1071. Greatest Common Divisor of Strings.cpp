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






class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, __gcd(str1.length(), str2.length()));
    }
};

// This implementation uses a loop to find the greatest common divisor (GCD) of two strings. 
// The function takes two strings str1 and str2 as input, and returns the largest string x 
// that divides both str1 and str2.

// The __gcd function is used to find the greatest common divisor of the lengths of str1 and str2. 
// If the concatenation of str1 and str2 is not equal to the concatenation of str2 and str1, 
// it means that str1 and str2 do not have a common divisor, and the function returns an empty string.

// Otherwise, the function returns the substring of str1 that starts at the beginning and has
// length equal to the greatest common divisor of the lengths of str1 and str2. This substring 
// is guaranteed to be the largest string that divides both str1 and str2.



