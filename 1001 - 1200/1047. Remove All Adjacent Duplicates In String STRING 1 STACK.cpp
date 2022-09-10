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
