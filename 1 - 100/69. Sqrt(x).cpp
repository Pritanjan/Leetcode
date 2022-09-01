// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        
        long long int i=0;
        // for(int i=0;i<INT_MAX;i++){
        
        while(i*i<=x)
            i++;
        
        return i-1;
    // }
        
    }
};



class Solution {
public:
    int mySqrt(int x) {       
        long long int ma=INT_MAX;
        long long int a=0;
        long long int ans=0;
        
        while(a<=ma){
            long long q=a+(ma-a)/2;
            
            if(q*q<=x){
               ans=q;
                a=q+1;
            }
            else
                ma=q-1;
        }
        return ans;
        
    }
};
