//https://leetcode.com/problems/maximum-swap/
//COMPANY TAG FB MICROSOFT

class Solution {
public:
    int maximumSwap(int num) {
        auto s = to_string(num);
        for(int i=0; i<s.size(); i++){
            auto a = max_element(s.rbegin(),s.rend()-i);
            if(s[i] != *a){
                swap(s[i], *a);
                break;
            }
        }
        return stoi(s);
    }
};
