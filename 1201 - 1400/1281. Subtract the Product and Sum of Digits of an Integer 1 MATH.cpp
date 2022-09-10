// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        
    // int z = n;
    int sum = 0;
    int p = 1;
    

        
    while(n!=0){

    	p = p * (n%10);
        sum +=   n%10;
	    n=n/10;
	    
        // sum += z%10;
        // z = z / 10;
	
    }

    return (p - sum );
    }
};

