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





// APPROACH 3  [ Using StringBuilder ]
// Here, we can use a stringstream to build the column title string by repeatedly calculating the
// remainder and updating the column number.

class Solution {
public:
    string convertToTitle(int columnNumber) {
        stringstream ss;
        while(columnNumber > 0) {
            columnNumber--;  // Adjust for 1-based indexing
            int rem = columnNumber % 26;
            ss << char('A' + rem);
            columnNumber /= 26;
        }
        
        string res = ss.str();
        reverse(res.begin(), res.end());  // Reverse the string
        return res;
    }
};





// APPROACH 4 [ Using a Mapping Array ]

// Here, we can create an array that maps the remainders to characters, 
// then build the column title by using this mapping array.

class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> mapping = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                 'U', 'V', 'W', 'X', 'Y', 'Z'};

        string columnTitle = "";
        while(columnNumber > 0) {
            columnNumber--;  // Adjust for 1-based indexing
            int rem = columnNumber % 26;
            columnTitle = mapping[rem] + columnTitle;
            columnNumber /= 26;
        }
        return columnTitle;
    }
};


