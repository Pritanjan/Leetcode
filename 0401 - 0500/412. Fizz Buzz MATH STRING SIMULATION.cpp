// APPROACH 1

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        
        for(int i=1;i<=n;i++){
            if(i%3 ==0)
                ans[i-1] += "Fizz";
            if(i%5 ==0)
                ans[i-1] += "Buzz";
            // if(i%3 ==0  && i%5==0)
            //     ans[i-1] += "FizzBuzz";
            if(ans[i-1].empty())
                ans[i-1] += to_string(i);
        }
        return ans;
    }
};





// APPROACH 2

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i = 1; i <= n; ++i) {
            string s;

            if (i % 3 == 0) s += "Fizz";
            if (i % 5 == 0) s += "Buzz";
            ans.push_back(s.empty() ? to_string(i) : s);

        }
        return ans;
    }
};



// 1. The function fizzBuzz takes an integer n as its argument and returns a vector of strings.
// 2. The vector ans is initialized to be empty.
// 3. A for loop is used to iterate from 1 to n.
// 4. For each number in the loop, a string s is initialized to be empty.
// 5. If the number is divisible by 3, the string s is appended with "Fizz".
// 6. If the number is divisible by 5, the string s is appended with "Buzz".
// 7. If the string s is still empty, meaning the number is not divisible by either 3 or 5,
//    then the number itself is converted to a string using the to_string function and
//    pushed into the ans vector.
// 8. If the string s is not empty, then it is pushed into the ans vector.
// 9. Once the loop finishes, the ans vector is returned.
    


// T.C. --> O(N)
// S.C. --> O(N)


