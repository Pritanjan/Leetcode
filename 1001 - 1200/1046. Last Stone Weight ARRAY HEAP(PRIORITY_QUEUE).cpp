// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        priority_queue<int> v(stones.begin(), stones.end());
      
        while(v.size() > 1){
            int x = v.top();
                v.pop();
            
            int y = v.top();
                v.pop();
           
            if(y!=x){
                v.push(x-y);
            }
            
            if(v.size() == 0)
                return 0;
        }
        return v.top();
        // return v.empty()? 0 : v.top();
    }
};
