// APPROACH 1

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m1;                        // m1 : first is key, second is frequent
        multimap <int, int, greater<int>> m2;    // m2 first is frequent, second is key
        
        for(auto i : nums) m1[i]++;        
        for(auto i : m1)   m2.insert(make_pair(i.second, i.first));
        
        for(auto i : m2) {
            ans.push_back(i.second);
            k--;
            if(!k) break;
        }         
        return ans;
    }
};





// APPROACH 2  Using Hash Map & Min-Heap Priority Queue

// S1 - Use a hash map to count the frequency of each element in the array.
// S2 - Use a priority queue (min-heap) to keep the top K frequent elements based on their frequencies.
// S3 - Finally, extract the top K elements from the priority queue.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(auto i : nums) freqMap[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minHeap
        for(auto& entry : freqMap) {
            pq.push({entry.second, entry.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


// OR
// Using Priority Queue (Heap)


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int i : nums) ump[i]++;

        auto compare = [&](const int a, const int b) {
            return ump[a] > ump[b]; // Compare in descending order
        };

        priority_queue<int, vector<int>, decltype(compare)> pq(compare);

        for(auto& i : ump) {
            pq.push(i.first);
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};






// APPROACH 3 Using Hash Map & Sorting

// First, use a hash map to count the frequency of each element in the array.
// Then, sort the elements based on their frequencies in descending order.
// Finally, extract the top K elements from the sorted list.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(auto i : nums) freqMap[i]++;

        vector<pair<int, int>> v(freqMap.begin(), freqMap.end());
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> res;
        for(int i=0; i<k; ++i) {
            res.push_back(v[i].first);
        }
        return res;
    }
};






// APPROACH 4 Using Hash Map & Buckt Sort

// First, use a hash map to count the frequency of each element in the array.
// Then, create a vector of buckets where each bucket holds elements with the same frequency.
// Finally, extract the top K elements from the buckets.
    
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freqMap;
        for(auto i : nums) freqMap[i]++;

        vector<vector<int>> v(n+1);
        for(auto& i : freqMap) {
            v[i.second].push_back(i.first);
        }

        vector<int> res;
        for(int i=n; i>=0 && res.size()<k; --i) {
            for(int j : v[i]) {
                res.push_back(j);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};





// A5 - Using Multiset

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int i : nums) ump[i]++;

        multiset<pair<int, int>> frequencySet;
        for(auto& i : ump) {
            frequencySet.insert(make_pair(i.second, i.first));
        }

        vector<int> res;
        auto it = frequencySet.rbegin();
        for(int i=0; i<k; ++i) {
            res.push_back(it -> second);
            ++it;
        }
        return res;
    }
};






// A 6 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        
        vector<pair<int, int>> v;
        for(auto i : mp) v.push_back({i.second, i.first});
        
        priority_queue<pair<int, int>> pq(v.begin(), v.end());
        vector<int> ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if(k==0) return ans;
            
            ans.push_back(top.second);
            k--;
        }
        return ans;
    }
};











// First element to occur k times
// https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1

class Solution{
public:
    int firstElementKTime(int arr[], int n, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
            if(m[arr[i]] >= k) return arr[i];
        }
        return -1;
    }
};





