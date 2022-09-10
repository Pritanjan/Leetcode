// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int r= 0;
        while(x){
        	if(r>INT_MAX/10 || r<INT_MIN/10){
        		return 0;
			}
        	else{
            	r = r*10 + x%10;
            	x=x/10;
            	
        	}
        }
        return r;
    }
};

//  ADOBE GOOGLE AMAZON MICROSOFT BLOOMBERG
