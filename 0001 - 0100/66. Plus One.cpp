// APPROACH 1

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size(); i--; digits[i] = 0){
            if(digits[i]++ < 9) return digits;
        }
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};





// APPROACH 2

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
            if(digits[i] == 9) digits[i] = 0;
            else { // current digit is not 9 so we can safely increment by one
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






// APPROACH 3  Simple Addition

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; // initialize carry to 1
        
        // Traverse the digits from right to left
        for(int i=n-1; i>=0; i--) {
            int sum = digits[i] + carry; // add the carry to the current digit
            digits[i] = sum % 10; // set the current digit to the remainder
            carry = sum / 10; // update the carry
        }
        
        // If there is still a carry left, insert a new digit 1 at the beginning of the vector
        if(carry > 0) digits.insert(digits.begin(), 1);        
        return digits;
    }
};


// OR


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;        
        for(auto& d : digits) {
            int sum = d + carry;
            d = sum % 10;
            carry = sum / 10;
        }
        
        if(carry) digits.push_back(carry);
        
        reverse(digits.begin(), digits.end());
        return digits;        
    }
};





// APPROACH 4

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> tmp;
        int length = digits.size();
        
        if(length == 1) {
            if(digits[0] == 0) {
                tmp.push_back(1);
                return tmp;
            }
        }
        int flag = 1;
        int temp = length - 1;
        
        while(flag && (temp >= 0)) {
            if(digits[temp] != 9) {
                flag = 0;
                digits[temp]+=1;
                return digits;
            }
            digits[temp] = 0;
            temp = temp-1;
        }

        if(flag == 1) {
            tmp.push_back(1);
            for(int i=0; i<length; i++) {
                tmp.push_back(digits[i]);
            }
        }
        return tmp;
    }
};






// APPROACH 5 RECURSON

class Solution {
public:
    void recursive(vector<int> &digits, int idx){
        if(idx < 0) {
            digits.insert(digits.begin(), 1);
            return ;
        }
        if(digits[idx] == 9) {
            digits[idx] = 0;
            recursive(digits, idx-1);
        }
        else digits[idx] += 1;
    }

    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        recursive(digits, n-1);
        return digits;
    }
};


