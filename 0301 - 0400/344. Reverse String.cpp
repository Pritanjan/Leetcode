// APPROACH 1 [ 2 POINTER ]

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left  =  0;
        int right = s.size() - 1;
       
        while(left <= right){
            swap(s[left], s[right]);
                left++; right--;
        }   
    }
};

// T.C. O(N)
// S.C. O(1)







// APPROACH 2 [ STL ]

// This approach uses the reverse function from the STL algorithm library to 
// reverse the vector in place.


class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin() , s.end() ); 
        return s;
    }
};






// APPROACH 3


// This approach is to iterates over the first half of the vector and swaps each character
// with its corresponding character from the end of the vector using the swap function.

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++){
            swap(s[i], s[s.size()-1-i]);
        }
        // return s;
    }
};






// APPROACH 4

// This approach uses the XOR swap algorithm to swap each pair of characters in the vector. 
// The XOR swap algorithm is a bitwise operation that swaps two values without using a
// temporary variable. It modifies the input vector in place and has O(1) space complexity.


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left++;
            right--;
        }
    }
};






// APPROACH 5

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            s.push_back(s[i]);
        }
        s.erase(s.begin(), s.begin() + n);
        return ;        
    }
};






// APPROACH 6 [ Using recursion ]

// This approach uses a recursive function to swap the first and last characters of the string,
// then recursively swaps the remaining characters until the entire string is reversed. 
// It takes 3 arguments: the vector s, and the left and right indices of the current substring 
// being reversed. The reverseString function that's called externally just passes in the 
// entire vector to start the recursive process. 

class Solution {
public:
    void reverseString(vector<char>& s, int left, int right) {
        if(left >= right)  return ;
        
        swap(s[left], s[right]);
        reverseString(s, left+1, right-1);
    }

    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size()-1);
    }
};






// APPROACH 7 [ Using a stack ]

// This approach uses a stack to reverse the order of characters in the vector.
// It pushes each character onto the stack and then pops them off one by one,
// assigning them back into the vector in reverse order.

class Solution {
public:       
    void reverseString(vector<char>& s) {
        stack<char> st;
        for (char c : s) {
            st.push(c);
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};



// T.C. O(N)
// S.C. O(N)  -> due to stack 





