// A 1 

class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto &i : m) {
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> res;
        for(auto i : v) {
            int x = i.first;
            int f = i.second;
            while(f--) {
                res.push_back(x);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// OR 


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto it : nums) ump[it]++;
        
        sort(nums.begin(), nums.end(),[&](int a, int b){
            return ump[a] != ump[b] ? ump[a] < ump[b] : a > b;
        });       
        return nums;
    }
};






// A 2

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums) mp[i]++;
        
        // vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<int, int>> pq; 
        for(auto e : mp) pq.push({-e.second, e.first});
        
        vector<int> ans;
        while(!pq.empty()) {
            int freq = pq.top().first;
            for(int i=0; i<abs(freq); i++) {
                 ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};




