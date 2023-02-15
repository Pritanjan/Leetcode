// APPROACH 1

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i = num.size() - 1;
        int carry = 0;

        while (i >= 0 || k > 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i];
                i--;
            }
        
            if(k > 0) {
                sum += k % 10;
                k /= 10;
            }
            carry = sum / 10;
            res.push_back(sum % 10);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// The function first initializes an empty vector res to store the result. It then sets up 
// a loop to iterate through the digits of num and k from right to left, adding them
// together with any carry from the previous addition. The loop continues as long as there 
// are digits left in either num or k, or there is a carry from the previous addition.

// At each iteration, the function adds the digits from num and k, along with any carry 
// from the previous addition, and stores the result in a variable sum. 
// The function then calculates the new carry by dividing sum by 10 and truncating 
// the result. The function pushes the least significant digit of sum (i.e., sum % 10)
// to the result vector res.

// After the loop completes, the function reverses the result vector and returns it.

// Time Complexity = O(max(N, log K)), where N is the length of the input array num, 
// and K is the value of the input integer k.
// The function iterates through the digits of num and k once from right to left,
// so the time complexity is proportional to the length of the longer input.

// The space complexity of the function is O(max(N, log K)), as it uses an output 
// vector of length at most max(N, log K) to store the result. Additionally,
// it uses a few integer variables and constant amount of stack space for function calls, 
// so the overall space complexity is O(max(N, log K)).

// Note that the logarithm of K represents the number of digits in the decimal representation of K.
// This is because in each iteration of the loop, we divide K by 10 and the number of iterations 
// is proportional to the number of digits in K

