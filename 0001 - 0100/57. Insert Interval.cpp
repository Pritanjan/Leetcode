// A 1 -  Linear Search

class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        // Case 1: no overlapping case before the merge intervals  
        // Compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }    
        
        // Case 2: overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        // Case 3: no overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 2 - Binary Search

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // If the intervals vector is empty, return a vector containing the newInterval
        if(intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int tgt = newInterval[0];
        int L = 0;
        int R = n-1;

        // Binary search to find the position to insert newInterval
        while (L <= R) {
            int mid = (L + R) / 2;
            if(intervals[mid][0] < tgt) L = mid + 1;
            else R = mid - 1;
        }

        // Insert newInterval at the found position
        intervals.insert(intervals.begin() + L, newInterval);

        // Merge overlapping intervals
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            // If res is empty or there is no overlap, add the interval to the result
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            // If there is an overlap, merge the intervals by updating the end of the last interval in res
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)


