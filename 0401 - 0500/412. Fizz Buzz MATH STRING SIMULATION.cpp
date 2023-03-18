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



// T.C. --> O(N)
// S.C. --> O(N)


