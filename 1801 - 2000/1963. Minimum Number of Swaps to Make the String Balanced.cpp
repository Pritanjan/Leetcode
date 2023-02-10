class Solution {
public:
int minSwaps(string s) {
        int p = 0;
        int sum = 0;
        for(auto c:s){
            if(c == '['){
                sum++;
            }else{
                sum--;
            }
            p = min(sum, p);
        }
        if(p == 0) return 0;
        
        return ceil(-(p / 2.0));
    }
};


