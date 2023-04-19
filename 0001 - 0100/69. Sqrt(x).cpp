// APPROACH 1 


class Solution {
public:
    int mySqrt(int x) {
        long long int i=0;
        // for(int i=0;i<INT_MAX;i++){
        while(i*i<=x) i++;
        return i-1;
        // }
    }
};










// APPROACH 2 


class Solution {
public:
    int mySqrt(int x) {       
        long long int ma=INT_MAX;
        long long int a=0;
        long long int ans=0;
        
        while(a<=ma){
            long long q = a + (ma - a) / 2;
            if(q*q <= x) {
               ans = q;
                a=q+1;
            }
            else ma=q-1;
        }
        return ans;
        
    }
};








// APPROACH 3 [ BINARY SEARCH ]


class Solution {
public:
    int binarysearch(int n){
        int l = 0;
        int r = n;
        int mid ;
        long long  int ans = -1;
        
        while(l <= r){
            long long int mid = l + (r-l)/2;
            long long int sq = mid * mid ;
            
            if(sq == n)
                return mid;
            if(sq < n){
                ans = mid;
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return binarysearch(x) ;
    }
};






