// https://leetcode.com/problems/sort-the-people/

class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        vector<string> ans;
        vector<pair<int, string>> vp;
        
        for(int i=0; i<n.size(); i++){
            vp.push_back({h[i], n[i]});
            
        }        
        sort(vp.rbegin(), vp.rend());
        for(auto& it : vp) {
			ans.push_back(it.second);
		}
		return ans;
    }
};



class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> pq;
        
        for(int i = 0; i < heights.size(); i++){
            pq.push({heights[i], names[i]});
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};



