// APPROACH 1 [ Brute Force] 

// Here, we  iterate through each position in the haystack and check if the needle is present
// starting from that position.

class Solution {
public:
    int strStr(string haystack, string needle) {
        // If the "haystack" string is equal to the "needle" string, the function immediately returns 0.
        // since the substring is found at the beginning of the string.
        if(haystack == needle) return 0;
        
        int m = haystack.size();
        int n = needle.size();
        
        // It iterates through each possible starting index i of the substring in the haystack string. 
        // The loop runs from i=0 to i=m-n, since there is no need to search past that point.
        for(int i=0; i<=m-n; i++){
            //  initializing a variable j to 0, which will be used to iterate through the characters
            // of the needle string
            int j = 0;
            // Now, iterates through each character of the needle string.
            for(; j<n; j++){
                // It checks whether the current character in the haystack string matches the current 
                // character in the needle string. If they do not match, the loop is exited using 
                // the break statement.
                if(haystack[i+j] != needle[j]) break;
            }
            // checks whether all characters in the needle string have been matched. 
            // If they have, the function returns the current index i.
            if(j == n) return i;
        }
        // if the needle string is not found in the haystack string. The function 
        // returns -1 to indicate that the substring was not found.
        return -1;
    }
};


// T.C. --> O(m*n), where m & n is the length of the haystack string and needle string.
// The nested loops iterate through all possible substrings of length n in the haystack string,
// and for each substring, compare it with the needle string.

// S.C. --> O(1), as the algorithm uses a constant amount of extra space, independent of the input size.
// The space used is only for storing the loop counters and temporary variables.





// APPROACH 2

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        // initializing an variable i to 0. This variable will be used to iterate through
        // the haystack string.
        int i = 0;
        
        // It  will iterate until the index i is greater than m-n. Because once the needle 
        // string has less characters than the remaining haystack string,
        // there is no need to continue searching.
        while(i <= m-n){
            // It checks if the character at the current index i in haystack is equal to
            // the first character of needle.
            if(haystack[i] == needle[0]){
                // Now, checks if the substring of haystack starting from the current index i 
                // and of length n is equal to needle.
                if(haystack.substr(i,n) == needle) return i;
                // returns the index i if the needle string is found in the haystack string.
           }
           // increments the index i to check the next character in the haystack string
           i++;
        }
        // returns -1 if the needle string is not found in the haystack string.
        return -1;
    }
};

// T.C. --> O(m*n)
// The outer while loop will run m - n + 1 tim
// If the first character matches, the substr() function is called to compare the rest of the 
// needle string with the corresponding substring of the haystack string.
// Here, time complexity of substr() is proportional to the length of the substring being
// extracted, which is n in this case.
// Therefore, the time complexity of this function is O((m-n+1)*n), which can be simplified to O(m*n)
    
// S.C. --> O(1), 
// it uses only constant extra space for the integer variables and the substr() function 
// does not allocate any new memory





// APPROACH 3 [ C++ STL ]

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// T.C. --> O(m*n), where m &n is the length of the haystack string & needle string. 
// It is the worst-case scenario where every character in the haystack string needs to be
// compared to the first character of the needle string.

// S.C. --> O(1), It only uses a constant amount of additional memory regardless of the size 
// of the input strings.


// OR

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto it = search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
        if(it != haystack.end()) {
            return distance(haystack.begin(), it);
        }
        return -1;
    }
};


// OR


class Solution {
public:        
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        // if(pos != string::npos) return (int)(pos);
        if(pos != string::npos) return static_cast<int>(pos);
        return -1;
    }
};






// APPROACH 4 [KMP algorithm  for the string matching problem]

// The algorithm first constructs an array called "next" which is used to indicate the 
// next index to compare when there is a mismatch between the needle and haystack strings.
// It starts with j=0 and i=1 and updates the "next" array as it iterates through the needle string

// The strStr() function first checks if the needle string is empty, then it returns 0. 
// It then initializes j=0 and the "next" array using the getNext() function.
// It then iterates through the haystack string and updates the value of j based on the "next" array.
// If j equals the length of the needle string, it means a match has been found and the function 
// returns the starting index of the match

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i=1; i<s.size(); i++) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int j = 0;
        int next[needle.size()];
        getNext(next, needle);

        for(int i=0; i<haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if(haystack[i] == needle[j]) j++;
            if(j==needle.size()) return i-needle.size()+1;
        }
        return -1;
    }
};

// T.C. --> O(m+n)
// S.C. --> O(n), 







// APPROACH 5  [ Rabin-Karp Algorithm ]

class Solution {
public:
    const int prime = 101;
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        int needleHash = 0, haystackHash = 0;
        int primePower = 1;

        // Calculate hash of needle and first substring of haystack
        for(int i=0; i<=m-n; ++i) {
            if(i == 0) {
                for(int j=0; j<n; ++j) {
                    needleHash = (needleHash + needle[n-j-1] * primePower) % prime;
                    haystackHash = (haystackHash + haystack[n-j-1] * primePower) % prime;
                    if(j < n-1) primePower = (primePower * prime) % prime;
                }
            } 
            else haystackHash = (prime * (haystackHash - haystack[i-1] * primePower) + haystack[i + n-1]) % prime;

            if(haystackHash == needleHash) {
                int j;
                for(j=0; j<n; ++j) {
                    if(haystack[i + j] != needle[j]) break;
                }
                
                // Found the needle in the haystack
                if(j == n) return i;  
            }
        }
        return -1;  // Needle not found in haystack        
    }
};







// APPROACH 6 [ Boyer-Moore Algorithm ]

class Solution {
public:
    int ALPHABET_SIZE = 256;
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        // Empty needle is always found
        if(n == 0) return 0; 

        vector<int> v(ALPHABET_SIZE, -1);

        for(int i=0; i<n; ++i) v[needle[i]] = i;

        // Starting index for matching
        int s = 0;
        while(s <= m-n) {
            int j = n-1;

            while(j >= 0 && needle[j] == haystack[s + j]) --j;

            // Found the needle in the haystack
            if(j < 0) return s;

            // Shift based on bad character rule
            s += max(1, j - v[haystack[s+j]]);
        }
        return -1; // Needle not found in haystack
    }
};






// A 7 

class Solution {
    public int strStr(String haystack, String needle) {
        // If haystack is null or if needle is null or if the haystack string is shorter than the needle string Return -1 */
        if(haystack == null || needle == null || haystack.length() < needle.length()) return -1;
        // If the needle string is empty, return 0
        if(needle.equals("")) return 0;

        // Traverse through the haystack string
        for(int i=0; i<haystack.length() - needle.length() + 1; i++) {
            // If the character at the current index equals the character at the first needle index
            if(haystack.charAt(i) == needle.charAt(0))
                // check to see if the substring at the current index in the haystack */
                if(haystack.substring(i, needle.length() + i).equals(needle)) return i;  // return the current index
        }
        // Otherwise return -1
        return -1;
    }
}


// T.C. -  O(N + M)
// S.C. -  O(1)






// A 8 

