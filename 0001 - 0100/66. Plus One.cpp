// https://www.codingninjas.com/codestudio/problem-of-the-day/easy

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size(); i--; digits[i] = 0){
            
            if(digits[i]++ < 9)
                return digits;
        }
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1; i>=0; --i){
            // traverse digits from the last element (least significant)
        // since we begin with the last digit, increasing that digit by one
        // results in overflow.  Therefore, all elements PRIOR to digits[0]
        // need to be considered since there may be additional nines between
        // digits[0], ... , digits[n].
            if(digits[i] == 9)
                digits[i] = 0;
            else{ // current digit is not 9 so we can safely increment by one
                digits[i] += 1;
                return digits;
            }
                
        }
        
       // if the program runs to this point, each 9 is now a 0.
      // to get a correct solution, we need to add one more element with 
      // a value of zero AND set digits[0] to 1 (in the most significant position)
      // to account for the carry digit.
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};





class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; // initialize carry to 1
        
        // Traverse the digits from right to left
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry; // add the carry to the current digit
            digits[i] = sum % 10; // set the current digit to the remainder
            carry = sum / 10; // update the carry
        }
        
        // If there is still a carry left, insert a new digit 1 at the beginning of the vector
        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};




