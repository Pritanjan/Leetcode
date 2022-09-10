// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0){
            num-=i;
            i+=2;
            if(!num)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int nums) {
    	int L = 0
        int R = nums/2;
        int mid;
        
       while(L <= R){
       	   mid = (L+R)/2;
       	   
       	   if(mid*mid == num)
       	   		return true;
       	   	else if (mid*mid < num)
       	   		L = mid + 1;
       	   	else
       	   		R = mid - 1;
       	   		
	   }
	   return false;
    }
};
