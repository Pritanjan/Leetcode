// APPROACH 1

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





// APPROACH 2

