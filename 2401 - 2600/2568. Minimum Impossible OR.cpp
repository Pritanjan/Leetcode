class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ans = 1;
        
        unordered_map<int, int> ump;
        
        for(auto i : nums) ump[i]++;
        
        while(ump[ans] > 0){
            ans = ans * 2;
        }
        
        return ans;
    }
    
};



