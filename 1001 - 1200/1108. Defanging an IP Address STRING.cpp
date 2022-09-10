// https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        // return regex_replace(address, regex("[.]"), "[.]");
        
        string ans;
        for(auto str : address){
            if(str == '.')
                ans+="[.]";
            else
                ans+=str;
        }
        return ans;
    }
};


