class Solution {
public:
    string maskPII(string s) {
        int pos = s.find('@');
        if(pos!=-1){
            string ans;
            ans+= s[0]>=97?s[0]:s[0]+32;
            ans+="*****";
            ans+=s[pos-1]>=97?s[pos-1]:s[pos-1]+32;
            ans+=s.substr(pos,s.size()-pos);
            pos=8;
            while(pos<ans.size()){
                if(ans[pos]!='.'&&ans[pos]<97) ans[pos]+=32;
                pos++;
            }
            return ans;
        }
        string tmp;
        pos=0;
        while(pos<s.size()){
            if(s[pos]>=48&&s[pos]<=57) tmp+=s[pos];
            pos++;
        }
        string ans;
        if(tmp.size()==10) ans+="***-***-";
        else if(tmp.size()==11) ans+="+*-***-***-";
        else if(tmp.size()==12) ans+="+**-***-***-";
        else ans+="+***-***-***-";
        ans+=tmp.substr(tmp.size()-4,4);
        return ans;
    }
};





class Solution {
public:
    string maskPII(std::string S) {
        int idx = S.find("@");
        if (idx != -1) {
            std::transform(S.begin(), S.end(), S.begin(), ::tolower);
            std::string tmp = S.substr(0, idx);
            return tmp[0] + std::string("*****") + tmp[tmp.size() - 1] + S.substr(idx);
        }
        else {
            std::string digits;
            for (char c : S) {
                if (isdigit(c)) {
                    digits.push_back(c);
                }
            }
            int n = digits.size();
            if (n == 10) {
                return std::string("***-***-") + digits.substr(n - 4);
            }
            else {
                return std::string("+") + std::string(n - 10, '*') + std::string("-***-***-") + digits.substr(n - 4);
            }
        }
    }
};

int main() {
    Solution sol;
    std::string S1 = "LeetCode@LeetCode.com";
    std::string S2 = "1(234)567-890";
    std::cout << sol.maskPII(S1) << std::endl;  // Output: l*****e@leetcode.com
    std::cout << sol.maskPII(S2) << std::endl;  // Output: ***-***-7890
    return 0;
}








