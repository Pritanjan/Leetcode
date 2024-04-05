// A 1

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        if(s.empty()) return s;        
        for(int i=0; i<n-1; i++){
            if(abs(s[i] - s[i+1]) == 32){
                return makeGood(s.substr(0, i) + s.substr(i+2));                
            }
        }
        return s;
    }
};





// A 2 

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; ) {
            if (abs(int(s[i]) - int(s[i + 1])) == 32) {
                // Characters are of different cases and same letter
                s.erase(i, 2); // Remove both characters
                if (i > 0) {
                    // Move back one step to check if the previous character and the new character can react
                    i--;
                }
                n -= 2; // Decrease the size of the string accordingly
            } else {
                // Characters do not react, move to the next pair
                i++;
            }
        }
        return s;
    }
};
