// APPROACH 1

class Solution {
public:
    int numberOfSteps(int n) {
       int count = 0;
        while(n!=0){
            if(n&1)
                n -= 1;
            
            else
                n >>= 1;
                
            count++;
        }
        return count;
    }
};







// APPROACH 2

class Solution {
public:
    int numberOfSteps(int n) {
       int count = 0;
        while(n!=0){
            if(n%2 == 0){
                n /= 2;
                count++;
            }
            else{
                n -= 1;
                count++;
            }   
        }
        return count;
    }
};

