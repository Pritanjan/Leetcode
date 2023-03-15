// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0020%20271122%20Add%20Binary%20Strings.cpp

//  APPROACH 1

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        string s;
        
        while(i >= 0 or j >= 0 or c == 1){
            if(i >= 0){
                c += a[i] - '0';
                i--;
            }
            if(j >= 0){
                c += b[j] - '0';
                j--;
            }
            s += (c%2 + '0');
            c /=  2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

// 2. The addBinary function first initializes three variables: i and j to the lengths 
//    of a and b minus 1, respectively, and carry to 0. It then initializes an empty 
//    string res to store the result.

// 2. The function then enters a loop that iterates until both i and j are less than 0 and 
//    carry is 0. In each iteration, it computes the sum of the current digits from a, b, 
//    and carry. If there is a digit at the corresponding index in a or b, it adds that digit
//    to the sum; otherwise, it adds 0.

// 3. The function then appends the least significant digit of the sum to res, and updates the 
//    value of carry to be the most significant digit of the sum. It then decrements both i and j.

// 4. Finally, the function returns the string res, which contains the sum of a and b in binary form.

// OR 

class Solution {
public:
    string addBinary(string a, string b) {
        //c=carry, i=last index of string a, j=last index of string b
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;   
        string s;   // result string
        
        while(i >= 0 or j >= 0 or c == 1){
            c += i >= 0 ? a[i--] - '0' : 0;  // carry=carry+ int value of a[i] (subtracting ascii value of '0' from a[i] gives integer value of carry)

            c += j >= 0 ? b[j--] - '0' : 0;  // carry=carry + int value of b[j]
            
            s = char(c % 2 + '0') + s;   //  c%2 means insert 0 if carry==0  or carry==2 (1+1) because ('1'+'1'=0 in binary) else insert 1 ('0'+'1'=1). Adding '0' to convert in ascii from integer 
            c /= 2;   //if c==2 or 3, there is a carry i.e 1 otherwise no carry (3 in case if prev c=1 and a[i]=1 and b[i]=1)
            
            // s = (c&1) + s;
            // c = c >> 1;
        }
        return s;
    }
};



// APPROACH 2

class Solution{
public:	
	string addBinary(string A, string B) {
	    if(A.size() > B.size())
	        return addBinary(B, A);
	        
	    int size = B.size() - A.size();
	    
	    string s;
	    for(int i=0; i<size; i++){
	        s.push_back('0');
	    }
	    
	    A = s + A;
	    string ans;
	    char carry = '0';
	    
	    for(int i=A.size()-1; i>=0; i--){
	        if(A[i] == '0' and B[i] == '0'){
	            if(carry == '1'){
	                ans.push_back('1');
	                carry = '0';
	            }
	            else{
	                ans.push_back('0');
	                carry = '0';
	            }
	        }
	        else if(A[i] == '1' and B[i] == '1'){
	            if(carry == '1'){
	                ans.push_back('1');
	                carry = '1';
	            }
	            else{
	                ans.push_back('0');
	                carry = '1';
	            }
	        }
	        else if(A[i] != B[i]){
	            if(carry == '1'){
	                ans.push_back('0');
	                carry = '1';
	            }
	            else{
	                ans.push_back('1');
	                carry = '0';
	            }
	        }

	    }
        	        
	   if(carry == '1')
            ans.push_back(carry);
	            
	   reverse(ans.begin(), ans.end());
	   int idx = 0;
	       
	   while(idx + 1 < ans.size() and ans[idx] == '0'){
	       idx++;
	   }
	   
	   return (ans.substr(idx));
	}
};






class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int carry = 0, i = m - 1, j = n - 1;
        string result = "";
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
    }
};

