// A 1

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1073741824)
            return true;
        for(int i=0; i<30; i++){
            if(n == pow(2,i))
                return true;
        }
        return false;
    }
};






// A 2

