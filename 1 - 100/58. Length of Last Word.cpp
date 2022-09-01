//https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream s1(s);
        string s2;
        
        while(s1 >> s2){}
        
        return s2.size();
    }
};



class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != ' ')
                size++;
            // and size > 0  is added because if space is given 
            // in the last 
            // s = "   fly me   to   the moon  "
            if(s[i] == ' ' and size > 0)
                return size;
        }
        return size;
    }
};
