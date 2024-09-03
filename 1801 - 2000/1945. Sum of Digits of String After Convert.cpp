// A 1

class Solution {
public:
    int getLucky(string s, int k) {
        string numToString ="";
        for(auto ch : s) {
            numToString += to_string(ch -'a' +1);
        }

        while(k-- > 0) {
            int sum = 0;
            for(char digit : numToString) {
                sum += digit -'0';
            }
            numToString  = to_string(sum);
        }
        return stoi(numToString);
    }
};



