// A 1

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=nums.size()-1; i>=0; i--){
            bool flag = false;
            for(auto& p : res) {
                if(find(p.begin(), p.end(), nums[i]) == p.end()) {
                    p.push_back(nums[i]);
                    flag = true;
                    break;
                }
            }            
            if(!flag) res.push_back({nums[i]});            
        }
        return res;
    }
};


// OR


const int N=205;
int cnt[N];
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++) cnt[nums[i]]++;
        vector<vector<int>> ans; 
        while (true) {
            bool ok=true;
            vector<int> res;
            for (int i=1; i<=n; i++) if (cnt[i]) res.push_back(i),cnt[i]--;
            if (res.empty()) break;
            ans.push_back(res);
        }
        return ans;
    }
};


// OR


const int N = 205;
int cnt[N];

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        // Initialize cnt array
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[nums[i]]++;

        vector<vector<int>> ans;
        while(true) {
            bool ok = true;
            vector<int> res;
            for(int i=1; i<=n; i++) {
                if(cnt[i]) {
                    res.push_back(i);
                    cnt[i]--;
                    ok = false; // Set ok to false as we found a non-empty element
                }
            }
            if(ok) break; // Break if we didn't find any non-empty elements
            ans.push_back(res);
        }
        return ans;
    }
};






// A 2

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // mp[i] means the number i is left now
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;

        vector<vector<int>> ans;
        while(!mp.empty()) {
            vector<int> V;
            // Enumerate the remaining numbers
            for(auto it = mp.begin(); it != mp.end(); ) {
                // add it->first to the answer
                it->second -= 1;
                V.push_back(it->first);
                // it->first is exhausted, remove from mp
                if(it->second == 0) it = mp.erase(it);
                else it++;
            }
            ans.push_back(V);
        }
        return ans;
    }
};






// A 3  - count frequency

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        
        vector<vector<int>> ans;
        for(auto c : nums) {
            if(freq[c] >= ans.size()) {
                ans.push_back({});
            }            
            // Store the integer in the list corresponding to its current frequency.
            ans[freq[c]].push_back(c);
            freq[c]++;
        }
        return ans;
    }
};
