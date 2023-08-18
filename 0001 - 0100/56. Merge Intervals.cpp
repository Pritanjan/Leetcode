// APPROACH 1 SORTIONG

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());            
        vector<vector<int>> merge;
        for(auto i : intervals){
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if(merge.empty() || i[0] > merge.back()[1] ) merge.push_back(i);
            else merge.back()[1] = max(merge.back()[1], i[1]);	// otherwise, there is overlap, so we merge the current and previous intervals.
        }         
        return merge;
    }
};

// Time complexity : O(nlogn)

// Other than the sort invocation, we do a simple linear scan of the list,
// so the runtime is dominated by the O(n logn) complexity of sorting.
// Space complexity : O(logN) or O(n))
// If we can sort intervals in place, we do not need more than constant additional space, 
// although the sorting itself takes O(logn) space. Otherwise, 
// we must allocate linear space to store a copy of intervals and sort that.




// OR


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());            
        vector<vector<int>> merge{intervals[0]};
        for(int i=0; i<intervals.size(); i++){ 
            if(intervals[i][0] > merge.back()[1]) merge.push_back(intervals[i]); 
            else merge.back()[1] = max(merge.back()[1], intervals[i][1]);
        }    
        return merge;
    }
};






// APPROACH 2

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts,ends;
        for(int i=0; i<n; i++) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for(int i=0, j=0; i<n; i++) {
            if(i == n-1 || starts[i+1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        }
        return res;
    }
};






// APPROACH 3 USE PRIORITY QUEUE

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        
        for(vector<int>& interval : intervals) {
            pq.push(interval);
        }
        
        vector<vector<int>> res;
        while(!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            
            if(res.empty() || current[0] > res.back()[1]) res.push_back(current);
            else res.back()[1] = max(res.back()[1], current[1]);
        }        
        return res;
    }
};




