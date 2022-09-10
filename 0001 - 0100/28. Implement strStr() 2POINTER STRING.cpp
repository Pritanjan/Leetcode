//https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack == needle)
            return 0;
        
        int m = haystack.size();
        int n = needle.size();
        for(int i=0; i<=m-n; i++){
            int j = 0;
                for(; j<n; j++){
                    if(haystack[i+j] != needle[j])
                        break;
                }
            
            if(j == n)
                return i;
        }
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


