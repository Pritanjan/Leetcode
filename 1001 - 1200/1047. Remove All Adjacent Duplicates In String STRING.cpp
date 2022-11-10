class Solution {
public:
    string removeDuplicates(string s) {
        string ans;  // store ans
        for(char i : s){	// traverse each element in the string
            if(ans.size() == 0)			// if string is empty then just push element simply
                ans.push_back(i);	
            else if(i == ans.back())	//or if the current element is equal to the last element of the string then it's the adjacent one, so delete it.
                ans.pop_back();
            else	
                ans.push_back(i);	 //else just push the element simply
        }	
        return ans;	 	//return the string
    }
};





//  use string as a stack.

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0 ;
        for(int j=1; j<s.length(); j++){
            i < 0 || s[i] != s[j] ?  s[++i] = s[j] : --i;
        }
        return s.substr(0,i+1);
    }
};
