// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m1;    // m1 : first is key, second is frequent
        multimap <int, int, greater<int>> m2;  // m2 first is frequent, second is key
        
        for(auto i : nums){
            m1[i]++;
        }
        
        for(auto i : m1){
            m2.insert(make_pair (i.second, i.first));
        }
        for(auto i : m2){
            ans.push_back(i.second);
            k--;
            
            if(!k)
                break;
        }
        
        return ans;
    }
};
