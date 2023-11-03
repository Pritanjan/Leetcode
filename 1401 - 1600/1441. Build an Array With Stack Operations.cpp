// A 1 -  Simulation

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 0; 
        for(int i=1; i<=n and curr < target.size(); i++) {
            res.push_back("Push");
            if(i != target[curr]) res.push_back("Pop");
            else curr++;
        }
        return res;
    }
};






// A 2 

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        queue<int> que;
        for(int i=1; i<=n; i++) {
            que.push(i);
        }

        int idx = 0;
        while(idx < target.size()) {
            int curr = que.front();
            que.pop();

            if(curr == target[idx]) {
                res.push_back("Push");
                idx++;
            }
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};






// A 3  - 

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 1; 
        for(int i=0; i<target.size(); i++) {
            while(curr < target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                curr++;
            }
            if(curr == target[i]) {
                res.push_back("Push");
                curr++;
            }
        }
        return res;
    }
};






// A 4




