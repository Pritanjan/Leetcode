//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
//COMPANY TAG BLOOMBERG

//We will use stack pair to store the character along with its** contiguous count or frequency**

//Traverse the string and follow three steps:
	//if the current character is not same as the previous character:
		//push the element into stack
	//increment count/frequency of the character
	//if the frequency becomes equal to k:
		//remove the pair from the stack

//traverse the stack and add the character frequency number of times into the resultant string

//reverse the resultant string

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sp;
        string ans = "";
        
        for(int i=0; i<s.size(); i++){
            if(sp.empty() || s[i] != sp.top().first)
                sp.push({s[i],0});
            
            sp.top().second++;
            if(sp.top().second == k)
                sp.pop();
        }
        while(!sp.empty()){
            ans += string(sp.top().second, sp.top().first);
            sp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
