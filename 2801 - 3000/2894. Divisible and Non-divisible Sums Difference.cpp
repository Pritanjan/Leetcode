// A 1

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0; 
        int num2 = 0;
        for(int i=1; i<=n; i++) {
            if(i % m != 0) num1 += i; 
            else num2 += i;
        }
        return num1 - num2;
    }
};






// A 2

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n * n + n) / 2;
        int d = n / m;
        int div = m * (d*d + d) / 2;
        return sum - 2*div;
    }
};






// A 3


