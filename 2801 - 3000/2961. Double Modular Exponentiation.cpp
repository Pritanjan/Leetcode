// A 1

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for(int i=0; i<variables.size(); ++i) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            int A = 1;
            for(int j=0; j<b; ++j) A = (A * (a % 10)) % 10;
            
            int B = 1;
            for(int k=0; k<c; ++k) B = (B * A) % m;
            
            if(B == target) res.push_back(i);
        }
        return res;
    }
};





// A 2

class Solution {
public:
    int customPow(int base, int exp, int mod) {
        int res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % mod;
            
            exp /= 2;
            base = (base * base) % mod;
        }
        return res;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for(int i=0; i<variables.size(); ++i) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            int x = customPow(a, b, 10);
            int y = customPow(x, c, m);

            if(y == target) res.push_back(i);
        }
        return res;
    }
};






// A 3

