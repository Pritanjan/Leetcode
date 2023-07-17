// APPROACH1 USING 2 STACK

class Solution {
public:
    string decodeString(string s) {
        string res = "";

        stack<int> nums;
        stack<string> strs;
        
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(isdigit(s[i])) {
                cnt = 10 * cnt + (s[i] - '0');
            }
            else if(s[i] == '[') {
                nums.push(cnt);
                strs.push(res);
                cnt = 0; res = "";
            }
             else if(s[i] == ']') {
                int k = nums.top(); nums.pop();
                string next = strs.top(); strs.pop();
                for (int j = 0; j < k; ++j) 
                    next += res;
                res = next; 
            }else{
                res += s[i];
            }
        }
        return res;
    }
};

// The idea of the solution is to use two stacks, one for integers (representing the k values) 
// and one for strings (representing the previous strings that need to be repeated).

// Time complexity - O(N), where N is the length of the input string, 
// because each character is processed only once. 

// Space complexity - O(N), because the two stacks could store up to N/2 elements in the worst case 
// (e.g. when the input string has alternating digits and brackets).

// Overall, this solution is a simple and efficient way to solve the problem using stacks.






// APPROACH 2 RECURSION


class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeHelper(s, i);
    }

private:
    string decodeHelper(const string& s, int& i) {
        string res = "";

        while(i < s.length() && s[i] != ']') {
            if(isdigit(s[i])) {
                int cnt = 0;
                while(i < s.length() && isdigit(s[i])) {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }

                i++;  // Skip the '[' character
                string decoded = decodeHelper(s, i);
                i++;  // Skip the ']' character

                while(cnt--) res += decoded;
                
            } 
            else {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};


// T.C. --> O(N^2)
