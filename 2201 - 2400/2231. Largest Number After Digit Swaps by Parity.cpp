// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        string even=" ", odd=" ";
        
        for(int i=0; i<s.size(); i++){
            (s[i] - '0') %2==0 ? even += s[i] : odd +=s[i];
            
        }
        
        sort( odd.rbegin(), odd.rend());
        sort(even.rbegin(),even.rend());
        
        for(int i=0,j=0,k=0; i<s.size(); i++){
            s[i] = (s[i]-'0')%2==0 ? even[j++] : odd[k++];
            
        }
        
        
        return stoi(s);
    }
};
