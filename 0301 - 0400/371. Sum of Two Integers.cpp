// A 1

class Solution {
public: 
    int getSum(int x, int y){
        if(y == 0) return x;
        else return getSum( x^y, (x & y) << 1);
    }
};





// A 2

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};

