// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        // vector<int> ans;
        for(int i=0; i<p.size()-1; i++){
            for(int j=i+1; j<p.size(); j++){
                if(p[i] >= p[j]){
                    // ans.push_back(p[i]-p[j]);
                    p[i] = p[i] - p[j];
                    break;
                }
            }
        }
        return p;
    }
}; 


