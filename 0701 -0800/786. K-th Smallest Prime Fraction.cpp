// A 1 

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


