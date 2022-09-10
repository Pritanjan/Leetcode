class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        int pos = 1;    // to find out the position where we find prefix string
        string x;  // to store word
        int n = w.size();
	    for(char i : s){  // itreate over scentece (i.e. s)
            if(i == ' '){   // now if space is occured we will check whether prefix is occured or not
                if(x.size() >= n && x.substr(0,n) == w)
                    return pos;                    
                x = "";
                pos += 1;
            }
            else
                x += i;
        }
        if(x.size() >= n and x.substr(0,n) == w)
            return pos;
        return -1;
    }
};


// x.size() >= s.size()  because if substring size < searchword size then deffinitely it wont be its preffix






class Solution {
public:
    int isPrefixOfWord(string s, string pref) {
        int n = s.length();
        int len = pref.length();
        int cnt = 1;
        for(int i = 0;i<n;i++){
            if(s[i] == ' '){
                cnt++;
                continue;
            }
            else{
                if(i == 0 || s[i-1] == ' '){
                    if(n-i >= len){
                        if(s.substr(i,len) == pref){
                            return cnt;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
