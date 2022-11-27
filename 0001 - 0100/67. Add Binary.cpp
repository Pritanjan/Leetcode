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

