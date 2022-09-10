class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(int i=0;i<=c;i++){
            for(int j=0;j<=c;j++){
                if((i*i)+(j*j)==c)
                    return true;
            }
        }
        return false;
    }
};


// WRONG
