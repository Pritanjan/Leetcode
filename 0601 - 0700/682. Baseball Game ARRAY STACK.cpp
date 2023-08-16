// APPROACH 1 use stack

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for(string& op : operations) {
            if(op == "+") {
                int top = scores.top();
                scores.pop();
                
                int newScore = top + scores.top();
                scores.push(top);
                scores.push(newScore);
            } 
            else if(op == "D") scores.push(2 * scores.top());
            else if (op == "C") scores.pop();
            else scores.push(stoi(op));
        }
        
        int res = 0;
        while(!scores.empty()) {
            res += scores.top();
            scores.pop();
        }        
        return res;        
    }
};

 



// APPROACH 2 use array

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;    
        for(string& op : operations) {
            int n = v.size();
            if(op == "+") v.push_back(v[n-1] + v[n-2]);
            else if(op == "D") v.push_back(2 * v[n-1]);
            else if(op == "C") v.pop_back();
            else v.push_back(stoi(op));
        }
        
        int res = 0;
        for(int i : v) {
            res += i;
        }        
        return res;
    }
};






// APPROACH 3



