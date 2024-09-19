// A 1

class Solution {
public:
    // Memoization to store already computed results
    unordered_map<string, vector<int>> memo;

    // Helper function to compute all possible results from the expression
    vector<int> diffWaysToCompute(string exp) {
        // If the expression is already computed, return from memo
        if (memo.find(exp) != memo.end()) {
            return memo[exp];
        }

        vector<int> res;

        // Iterate through each character in the expression
        for (int i = 0; i < exp.size(); ++i) {
            char c = exp[i];

            // If the current character is an operator
            if (c == '+' || c == '-' || c == '*') {
                // Divide the expression into two parts: left and right
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                // Compute all combinations of left and right results using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }

        // If there are no operators, it means it's a number, so just convert it to int
        if (res.empty()) {
            res.push_back(stoi(exp));
        }

        // Store the result in memo and return it
        memo[exp] = res;
        return res;
    }
};

