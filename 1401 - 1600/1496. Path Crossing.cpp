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

class Solution {
private:
    void coordinates(int& x, int& y, char dir) {
        if(dir == 'N') y++;
        else if(dir == 'S') y--;
        else if(dir == 'E') x++;
        else if(dir == 'W') x--;
    }
public:
    bool isPathCrossing(string path) {
        int size = 2001; // Adjust based on the constraints
        vector<vector<bool>> vis(size, vector<bool>(size, false));
        int x = size / 2, y = size / 2;

        vis[x][y] = true;
        for(char c : path) {
            coordinates(x, y, c);
            if(vis[x][y]) return true;
            else vis[x][y] = true;
        }
        return false;
    }
};




