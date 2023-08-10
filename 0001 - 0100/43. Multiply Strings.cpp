// APPROACH 1 [ Multiplication ]

class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1 == "0" || nums2 == "0") return "0";
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> v(n+m, 0);    // n + m = max no. of pdts.
        
        // build the number by multiplying one digit at a time
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                v[i+j+1] += (nums1[i] - '0') * (nums2[j] - '0');
                v[i+j] += v[i+j+1] / 10;
                v[i+j+1] %= 10;
            }
        }
        
        // skip leading zero
        int i = 0;
        while(i < v.size() && v[i] == 0) i++;
        
        // transform vector to a string 
        string ans;
        while(i < v.size()) {
            ans.push_back(v[i] + '0');
            i++;
        }            
        return ans;
    }
};



// OR


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m+n, 0);

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int pdt = (num1[i] - '0') * (num2[j] - '0');
                int sum = pdt + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string s;
        for(int i : res) {
            if(!(s.empty() && i == 0)) {
                s.push_back(i + '0');
            }
        }
        return s.empty() ? "0" : s;
    }
};






// APPROACH 2




