// APPROACH 1

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2 == 0) return n;
        else return 2*n;
    }
};





// APPROACH 2


class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n<<(n&1);
    }
};







// APPROACH 3

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n<<(n&1);
    }
};







// APPROACH 5

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return 2 / __gcd(2, n) * n;
    }
};







// APPROACH 6

class Solution {
public:
    int smallestEvenMultiple(int n) {
        int a = n;
        int b = 2;
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return (n * 2) / a;
    }
}; 







// APPROACH 7

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return lcm(2,n);
    }
}; 





