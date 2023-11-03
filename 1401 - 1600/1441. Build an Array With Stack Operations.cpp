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






// A 2 - Stack 





// A 3  - Stack Simulation

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






// A 3




