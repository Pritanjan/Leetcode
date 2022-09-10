// https://leetcode.com/problems/n-th-tribonacci-number/

//class Solution {
//public:
//    int tribonacci(int n) {
//        if(n==0)
//            return 0;
//        if(n==1 || n==2)
//            return 1;
//        else {
//            return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
//        }
//    }
//};


class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        int t0 = 0;
		int t1 = 1;
		int t2 = 1;
		int t3 = t0 + t1 + t2 ;
        while(n-- >2){
            t3 = t0 + t1 + t2 ,
        	t0 = t1,
 			t1 = t2,
 			t2 = t3;
 			
		}
        
        return t2;
    }
};




// t7 = t4 + t5 + t6

// t0 = 0
// t1 = 1
// t2 = 1
// t3 = t0 + t1 + t2 = 2
// t4 = t3 + t2 + t1 = 4
 
