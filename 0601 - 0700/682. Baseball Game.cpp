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



// OR


class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> v;
        for(size_t i=0; i<ops.size(); ++i) {
            if(ops[i] == "+") {
                int val1 = v[v.size() - 1];
                int val2 = v[v.size() - 2];
                sum += val1 + val2;
                v.push_back(val1 + val2);
            }
            else if(ops[i] == "C") {
                sum -= v.back();
                v.pop_back();
            }
            else if(ops[i] == "D") {
                int tmp = v.back() * 2;
                sum += tmp;
                v.push_back(tmp);
            }
            else {
                int num;
                istringstream(ops[i]) >> num;
                sum += num;
                v.push_back(num);
            }
        }        
        return sum;
    }
};





// APPROACH 3  Using a Circular Buffer

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v(operations.size(), 0);
        int idx = 0;
        
        for(string& op : operations) {
            int n = v.size();
            if(op == "+") {
                v[idx] = v[(idx-1 + n) % n] + v[(idx-2 + n) % n];
                idx = (idx + 1) % n;
            } 
            else if(op == "D") {
                v[idx] = 2 * v[(idx - 1 + n) % n];
                idx = (idx + 1) % n;
            }
            else if(op == "C") {
                idx = (idx - 1 + n) % n;
                v[idx] = 0;
            }
            else {
                v[idx] = stoi(op);
                idx = (idx + 1) % n;
            }
        }
        
        int res = 0;
        for(int i : v) {
            res += i;
        }        
        return res;
    }
};






// APPROACH 4

