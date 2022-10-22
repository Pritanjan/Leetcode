class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charracter;    //unordered map for storing the characters in t that we need to check for in s
        for(auto i : t)
            charracter[i]++;
        
        int cnt = 0;    //counts number of t's letters in current window
        int L = 0, min_len = INT_MAX, min_start = 0; 
        for(int R=0; R<s.size(); R++){
            if(charracter[s[R]] > 0)
                cnt++;    // means that this letter is in t   
            charracter[s[R]]--;     //reduce the count for the letter on which we are currently 
            
            if(cnt == t.length()){    //if current windows contains all of the letters in t
                while(L < R and charracter[s[L]] < 0)
                    charracter[s[L++]]++;         //move low ahead if its not of any significance        
                if(min_len > R-L)               
                    min_len = R-(min_start=L) + 1;      //update the min length
                charracter[s[L++]]++;     //move low ahaead and also increment the value
                cnt--;          //count-- as we are moving low ahead & low pointed to a char in t before
            }
        }            
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);    
    }
};



