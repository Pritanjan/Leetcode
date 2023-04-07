

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
            if(j == n)
                return i;
        }
        // if the needle string is not found in the haystack string. The function 
        // returns -1 to indicate that the substring was not found.
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size();
        int n = needle.size();
        int i = 0;
        
        while(i <= m-n){
           if(haystack[i] == needle[0]){
                if(haystack.substr(i,n) == needle)
                    return i;
           }
              i++;
        }
        return -1;
    }
};





class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

