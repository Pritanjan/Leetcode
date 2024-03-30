// A 0 - TLE

class Solution {
public:
    int atMostK(vector<int>& arr, int n, int k) {
        int cnt = 0;
        int L = 0, R = 0;
        unordered_map<int, int> ump;

        while (R < n) {
            if (ump.find(arr[R]) == ump.end()) ump[arr[R]] = 0;
            ump[arr[R]]++;

            while (ump.size() > k) {
                ump[arr[L]] = ump[arr[L]] - 1;
                if (ump[arr[L]] == 0) ump.erase(ump[L++]);
            }
            cnt += R - L + 1;
            R++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        return atMostK(arr, n, k) - atMostK(arr, n, k - 1);
    }
};
