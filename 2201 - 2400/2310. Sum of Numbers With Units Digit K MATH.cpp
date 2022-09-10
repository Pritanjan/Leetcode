//Assume the size of the set is n, and the numbers in the set are A1, A2,..., An

//A1 + A2 + ... + An = sum
//All numbers must have k as the unit digit
//So A1 + A2 + ... + An = n*k + 10*(a1 + a2 + .. + an) = sum

//Which (a1 + a2 + .. + an) can be any number.

//For example:
//sum = 58, k = 9 => we have n*k = 2*9 = 18, and 10*(a1 + a2) = 58 - 18 = 40. So a1 + a2 = 4

//Just find the minimum number satisfying the condition (n*k)%10==sum%10



//https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/

class Solution {
public:
    int minimumNumbers(int n, int k) {
        if(n==0) return 0;
        for(int i=1; i<=10; i++){
            if(k*i <= n && (i*k) %10 == n%10)
                return i;
        }
        return -1;
    }
};
