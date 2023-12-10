// A 1

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int res = 0;
        for(int i=0; i<n; ++i) {
            if(batteryPercentages[i] > 0) {
                ++res;
                for(int j=i+1; j<n; ++j) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return res;
    }
};






// A 2

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cur = 0, ret = 0;
        for (auto v : batteryPercentages) {
            // if (v - cur > 0){
                // ++cur;
            // }
            cur += v > cur;
        }
        return cur;
    }
};
