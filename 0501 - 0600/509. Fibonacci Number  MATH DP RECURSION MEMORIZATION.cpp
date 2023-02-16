// https://leetcode.com/problems/fibonacci-number/discuss/2243893/6-c-2-solution-easy-solution-6

Fibonacci Number -> It is a series in which a number is sum of 2 previous number.
 0,1,1,2,3,5,8,13......
 
[509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
	
**METHOD 1 -> RESURSIVE**  
Using mathmatical recursive implementation .

	class Solution {
	public:
		int fib(int n) {
			if(n==0)        // base case
				return 0;
			else if(n==1)   // base case
				return 1;
			else{
				return fib(n-1) + fib(n-2); 
			}
			// return fib(n)
		}
	};
// T.C. --> exponential (as every function calls 2 other functions)
If the original recursion tree were 

							  fib(5)   
						 /                \
				   fib(4)                fib(3)   
				 /        \              /       \ 
			 fib(3)      fib(2)         fib(2)   fib(1)
			/    \       /    \        /      \
	  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
	  /     \
	fib(1) fib(0)

<hr>
<br>


**METHOD 2 -> DP**
Avoiding the repeated work done in approach 1 by storing the Fibonacci number we calculated so far.

	class Solution {
	public:
		int fib(int n) {
		    // Declare an array to store Fibonacci numbers.
			int F[n+1];         
			F[0] = 0;
			F[1] = 1;
        
			for(int i=2; i<=n; i++){
				// Add the previous to no to get the next number.
				F[i] = F[i-1] + F[i-2];
			}
			return F[n];
		}
	};
	
<br>

**METHOD 3 (Space Optimized Method 2)**
We can optimize the space used in method 2 by storing the previous two numbers only because that is all we need to get the next Fibonacci number in series.

	class Solution {
	public:
		int fib(int n) {
			int i, a = 0, b = 1, c = i;
			if(n==0)
				return 0;
        
			for(i=2; i<=n; i++){
				c = a + b;
				a = b;
				b = c;
			}
			return b;
		}
	};

T.C. -> O(n)
S.C. -> O(1)



			

			

			
// https://practice.geeksforgeeks.org/problems/202d95ecdeec659401edc63dd952b1d37b989ab8/1		
			
// next number is the sum of the K preceding numbers
			
class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        long long sum=0;
        for(int i=0;i<K;i++){
            sum+=GeekNum[i];
        }
        
        GeekNum.push_back(sum);
        int j=0;
        
        for(int i=K+1;i<N;i++){
            GeekNum.push_back(2*GeekNum[i-1]-GeekNum[j++]);
        }
        return GeekNum[N-1];
    }
};


			
			
			
