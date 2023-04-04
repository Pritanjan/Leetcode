// APPROACH 1

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 0) return 0;

        int totalDuration = 0;
        for (int i=1; i<n; i++) {
            totalDuration += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return totalDuration + duration;
    }
};






// APPROACH 2

