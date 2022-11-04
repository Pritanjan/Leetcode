class Solution {
public:
    string convertToBase7(int n) {
        if(n < 0)
            return "-" + convertToBase7(-n);
        if(n < 7)
            return to_string(n);
        
        return convertToBase7(n/7) + to_string(n%7);        
    }
};



class Solution {
public:
    string convertToBase7(int num) {
        return num/7 == 0 ? to_string(num) : convertToBase7(num/7) + to_string(abs(num)%7);
    }
};
