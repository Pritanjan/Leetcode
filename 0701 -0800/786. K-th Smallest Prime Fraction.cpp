// A 1 - Binary search 

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Define the boundaries of the binary search
        double L = 0, R = 1;
        vector<int> res;

        // Binary search to find the kth smallest fraction
        while (L < R) {
            double mid = (L + R) / 2;
            int cnt = 0;
            double maxFract = 0;

            // Use two pointers to count fractions <= mid
            for (int i = 0, j = 1; i < arr.size() - 1; i++) {
                while (j < arr.size() && arr[i] > mid * arr[j]) {
                    j++;
                }
                cnt += arr.size() - j;

                // Update maxFraction if arr[i] / arr[j - 1] is greater
                if (j < arr.size() && maxFract < (double)arr[i] / arr[j]) {
                    maxFract = (double)arr[i] / arr[j];
                    res = {arr[i], arr[j]};
                }
            }

            // Adjust the boundaries of binary search
            if (cnt == k) break;
            else if (cnt < k) L = mid;
            else R = mid;
        }
        return res;
    }
};





// A 2 - using priority qyeye - Leetcode

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Create a priority queue to store pairs of fractions
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.size(); i++)
            pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
        
        // Iteratively remove the top element (smallest fraction) 
        // and replace it with the next smallest fraction
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second], {cur.first, cur.second}});
        }
        
        // Retrieve the kth smallest fraction from 
        // the top of the priority queue
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }
};


