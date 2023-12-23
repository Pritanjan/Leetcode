// A 1 

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> set;
        int x = 0;
        int y = 0;
        set.insert(to_string(x) + "#" + to_string(y));
        
        for(char c : path) {
            if(c == 'N') y++;
            else if(c == 'S') y--;
            else if(c == 'E') x++;
            else if(c == 'W') x--;

            string str = to_string(x) + "#" + to_string(y);
            if(set.count(str)) return true;
            else set.insert(str);
        }
        return false;
    }
};






// A 2 



