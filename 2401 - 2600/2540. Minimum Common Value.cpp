// A 1

class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                return a[i];
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};






// A 2


