// https://leetcode.com/problems/license-key-formatting/

// C++
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // To store the final string
    	string ans = "";
        // To count the charracter in order to insert '-' into the string
    	int cnt = 0;
    	
        // iterating loop from last 
    	for(int i=s.size()-1; i>=0; i--){
            // if - found then ignore it
    	    if(s[i] == '-')
    	        continue;
            // if we get word equal to k then set cnt = 0 & insert '-' in the ans string
    	    if(cnt == k){
    	        cnt = 0;
    	        ans += "-";
    	    }
            
            // converting the lower case word to upper case
    	    ans += toupper(s[i]);
    	    cnt++;
    	}
        // reverse the ans
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};



// JAVA
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        s = s.replace("-","");
        s=s.toUpperCase();
        
        for(int i=s.length()-1;i>=0;i--){
            if(i-k+1>0)
             s=s.substring(0,i-k+1)+"-"+s.substring(i-k+1, s.length());
             i=i-k+1;
        }
        return s ;
    }
}

