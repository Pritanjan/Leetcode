class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
            
        vector<vector<int>> merge;
        
        for(auto i : intervals){
        	// if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if(merge.empty() || i[0] > merge.back()[1] )
                merge.push_back(i);
            
			else	// otherwise, there is overlap, so we merge the current and previous intervals.
                merge.back()[1] = max(merge.back()[1], i[1]);
        }
        
            
        return merge;
    }
};

Time complexity : O(nlogn)

Other than the sort invocation, we do a simple linear scan of the list, so the runtime is dominated by the O(n\log{}n)O(nlogn) complexity of sorting.

Space complexity : O(logN) or O(n))

If we can sort intervals in place, we do not need more than constant additional space, although the sorting itself takes O(\log n)O(logn) space. Otherwise, we must allocate linear space to store a copy of intervals and sort that.
