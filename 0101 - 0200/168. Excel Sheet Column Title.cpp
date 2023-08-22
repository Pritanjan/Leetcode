// APPROACH 1

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        char ch;
        
        while(columnNumber--){
            ch = 'A' + columnNumber % 26;
            ans = ch + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};





// APPROACH 2 [ Using Recursion ]
// WE can solve this problem recursively by repeatedly dividing the column number by 26 and 
// converting the remainder into the corresponding character. Here's how you can do it:

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber <= 0) return "";
        int rem = (columnNumber - 1) % 26;
        return convertToTitle((columnNumber - 1) / 26) + char('A' + rem);
    }
};





// APPROACH 3 

