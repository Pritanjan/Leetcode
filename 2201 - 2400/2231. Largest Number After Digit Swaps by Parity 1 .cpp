// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        vector<int> even, odd, ar ;
        while(num){
            int n = num % 10;
            num = num/10;
            
            (n%2==0) ? even.push_back(n) : odd.push_back(n);
           
            ar.push_back(n);
            
        }
        
        sort( odd.rbegin(), odd.rend());
        sort(even.rbegin(),even.rend());
        
        int no = 0;
        int ne = 0;
        int ans= 0;
        
        for(int i=0; i<ar.size(); i++){
           // ans = ar[ar.size() -1-i] ? ans*10 + even[ne++] : ans*10 + odd[no++];
            if(ar[ar.size() -1-i] %2==0) 
                ans = ans*10 + even[ne++]; 
            else
                ans = ans*10 + odd[no++];
        }
        return ans;
    }
};
