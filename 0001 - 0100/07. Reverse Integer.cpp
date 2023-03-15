//  ADOBE GOOGLE AMAZON MICROSOFT BLOOMBERG


class Solution {
public:
    int reverse(int x) {
        int r= 0;
        while(x){
	    if(r>INT_MAX/10 || r<INT_MIN/10){
        	  return  0;
	    }
            else{
            	r = r*10 + x%10;
            	x=x/10;
            	
           }
        }
        return r;
    }
};



class Solution {
public:
    int reverse(int x) {
        long n = 0;
        while(x != 0) {
            n = n*10 + x%10;
            x = x/10;
        }
        return (int)n==n? (int)n:0;
    
    }
};





