// https://www.geeksforgeeks.org/simplify-directory-path-unix-like/

// APPROACH 1 [gfg] 
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






// APPROACH 2

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".")
                continue;
            if (dir == "..") {
                if (!dirs.empty())
                    dirs.pop_back();
            } else {
                dirs.push_back(dir);
            }
        }

        stack<string> st;
        for (const string& d : dirs) {
            st.push(d);
        }

        string simplified_path;
        while (!st.empty()) {
            simplified_path += "/" + st.top();
            st.pop();
        }

        return simplified_path.empty() ? "/" : simplified_path;
    }
};





// APPROACH 3

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;

        for (char c : path) {
            if (c == '/') {
                if (!dir.empty()) {
                    dirs.push_back(dir);
                    dir.clear();
                }
            } else {
                dir.push_back(c);
            }
        }

        if (!dir.empty()) {
            dirs.push_back(dir);
        }

        stack<string> st;
        for (const string& d : dirs) {
            if (d == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (d != "." && !d.empty()) {
                st.push(d);
            }
        }

        string simplified_path;
        while (!st.empty()) {
            simplified_path = "/" + st.top() + simplified_path;
            st.pop();
        }

        return simplified_path.empty() ? "/" : simplified_path;
    }
};



