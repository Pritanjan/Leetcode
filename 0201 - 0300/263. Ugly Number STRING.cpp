// APPROACH 1

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false; 
        
        while(n%2==0)
            n/=2;
        while(n%3==0)
            n/=3;
        while(n%5==0)
            n/=5;
        
        return n == 1;
        
    }
};




// APPROACH 2

class Solution {
public:
    bool isUgly(int n) {
        for(int i=2; i<6 && n; i++) {
            while(n % i == 0 )
                n /= i; 
        }
        return n == 1;
    }
};

// APPROACH 3
class Solution {
public:
    bool isUgly(int n) {        
         if(n<=0)
            return false; 
        vector <int> nums = {2,3,5};
        for(int i : nums){
            while(n % i == 0)
                n /= i;
        }
        return n==1;
    }
};
