class Solution {
public:
int minSwaps(string s) {
        int p = 0;
        int sum = 0;
        
        for(auto c : s){
            if(c == '[') sum++;
            else sum--;

            p = min(sum, p);
        }
        if(p == 0) return 0;
        
        return ceil(-(p / 2.0));
    }
};



// 1. Initialize two variables, "sum" and "p", to keep track of the balance of the string.

// 2. Loop through each character in the string. If the character is an opening square
//    bracket '[' , increment "sum" by 1. If it's a closing square bracket ']',
//    decrement "sum" by 1.

// 3. Update "p" with the minimum value between "p" and "sum". This helps keep track of 
//    the minimum balance encountered so far.

// 4. If "p" is 0, that means the string is already balanced, so return 0.

// 5. Otherwise, calculate the minimum number of swaps needed to balance the string by
//    taking the ceiling of negative half of "p".

// 6. Return the minimum number of swaps.

// The code uses the "ceil" function from the cmath library to round up to the nearest integer.
// This ensures that the minimum number of swaps is rounded up in case of a fractional result.
 


// Time complexity : O(n), where n is the length of the input string. 
// This is because we are looping through the entire string once, 
// so the time complexity is proportional to the length of the string.

// Space complexity: O(1), as we are only using a constant amount of extra space 
// to store the variables "sum" and "p".

// The use of the "ceil" function has a constant time complexity,
// so it does not affect the overall time complexity of the solution.





class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(auto& c : s) {
            if(c == '[') cnt++;
            else {
                if(cnt > 0) cnt--;
            }
        }
        return (cnt+1)/2;
    }
};







class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[')        st.push(ch);
            else if(!st.empty()) st.pop();
        }       
        return (st.size()+1)/2;
    }
};



