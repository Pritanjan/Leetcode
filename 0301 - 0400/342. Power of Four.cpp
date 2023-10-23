// A 1

class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0; i<30; i++ ){
            if(n == pow(4,i))
                return true;
        }
        return false;
    }
};






// A 2
// keep dividing the number by 4. In any iteration, if n%4 becomes non-zero and n is not 1 then 
// n is not a power of 4, eise, n is a power of 4. 

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        while(n != 1){
            if(n % 4 != 0) return false;
            n /= 4;
        }
        return true;
    }
};



