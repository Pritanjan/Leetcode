// https://www.geeksforgeeks.org/simplify-directory-path-unix-like/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string dir, res;
        res.append("/");

        int N = path.length();
        for(int i=0; i<N; i++) {
            dir.clear();
            while(path[i] == '/') i++;
            while(i < N && path[i] != '/') dir.push_back(path[i++]);
            if(dir.compare("..") == 0) {
                if(!stk.empty()) 
                    stk.pop();      
            }
            else if(dir.compare(".") == 0) continue;
            else if(dir.length() != 0) stk.push(dir);   
        }

        stack<string> stk1;
        while(!stk.empty()) {
            stk1.push(stk.top());
            stk.pop();
        }

        while(!stk1.empty()) {
            string temp = stk1.top();
            if (stk1.size() != 1) res.append(temp + "/");
            else res.append(temp);

            stk1.pop();
        }
        return res;
    }
};


