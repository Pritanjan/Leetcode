class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        
        while(n>0){
            ans += n%k;
            n/=k;
        }
        
        // for(; n>0; n/=k)
        //     ans +=n%k;
        
        
        return ans;
    }
};

//The general steps for converting a base 10 or "normal" number into another base are:
//
//1. First, divide the number by the base to get the remainder. This remainder is the first, i.e. least significant, digit of the new number in the other base
//2. Then repeat the process by dividing the quotient of step 1, by the new base. This time, the remainder is the second digit, i.e. the second least significant.
//3. Repeat this process until your quotient becomes less than the base. This quotient is the last digit, i.e. the most significant digit.
//
// So here, instead of creating the number, we are adding up the remainders so as to get the result directly.
//

// class Solution {
// public:
//     int sumBase(int n, int k) {
//         int que , rem, num = 0,z, ans=0;
//         que = n;
        
//         while(que>=k){
//             rem = n%k;
//             que = n/k;
//             num = que*10 + que;
//         }
//         int rev = 0;
//         while(num!=0){
            
//             rev = rev + num % 10; 
//             num = num / 10;
//         }
//         return rev;
//     }
// };
