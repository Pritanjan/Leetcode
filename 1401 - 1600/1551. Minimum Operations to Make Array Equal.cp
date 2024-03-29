// APPROACH 1

class Solution {
public:
    int minOperations(int n) {
        if(n % 2 == 0)
             return pow(n/2, 2) ;
        else
            return (n/2)*(n/2 + 1);
    }
};


// n = 7 (ODD)
// 1 3 5 7 9 11 13 
// | | |
// 6 4 2 
    // 2(3, 2, 1)
    // 2 * 3 * (3+1)/2
    // 12

// ans = (n/2)(n/2 + 1)

    
    
// n = 6 (EVEN)
// 1 3 5 7 9 11
// | | |
// 5 3 1
    // 9
    
// ans = (n/2)^ 2    

    
    
    
    
// 1 --> 0
// 2 --> 1
// 3 --> 2     3 + -1
// 4 --> 4     4 + 0
// 5 --> 6     5 + 1
// 6 --> 9     6 + 3
// 7 --> 12    7 + 5






// APPROACH 2

class Solution {
public:
    int minOperations(int N) {
        int mid=N/2;
        return N%2==0?(long)mid*(long)mid:(long)mid*(long)(mid+1);
    }
};

