// APPROACH 1 

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




// APPROACH 2

