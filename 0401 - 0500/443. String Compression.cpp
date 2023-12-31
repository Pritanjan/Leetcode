// A 1

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;              // for taversing the entire charracter
        int Index = 0;          // storing the count of a valid charracter
        int n = chars.size();   // size  of charracter
        while(i < n) {
            int j = i+1;      // to compare with the next charracter
            // now traverse untill we have the same the same charracter & make increment in j. 
            while(j < n and chars[i] == chars[j]) j++;
                        
            // Now, either the vector has been traverse completely 
            // or new character has been encountered.
            // storing the oldchar
            chars[Index++] = chars[i];
            
            // count of a charracter will be j - i as j has been incrmented untill the charracter is same
            int cnt = j - i;            
            if(cnt > 1){
                // Now converitng count into string and stroing in ans
                string c = to_string(cnt);
                for(char ch : c){
                    chars[Index++] = ch;
                }
            }
            // Now going to the new charracter as by i = j we have ignore all the first similar charracter
            i = j;
        }
        return Index;
    }
};


// OR


class Solution {
public:
    int compress(vector<char>& chars) {    
        int index = 0;
        int i = 0;
        while (i < chars.size()) {
            char c = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == c) {
                i++;
                count++;
            }
            chars[index] = c;
            index++;
            if (count > 1) {
                string s = to_string(count);
                for (int j = 0; j < s.size(); j++) {
                    chars[index] = s[j];
                    index++;
                }
            }
        }
        return index;
    }
};






// A 2 

