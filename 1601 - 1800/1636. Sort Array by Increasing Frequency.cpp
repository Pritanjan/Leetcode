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






// A 2 


