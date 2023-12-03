// A 1

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        int n = mountain.size();
        for(int i=1; i<n-1; ++i) {
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i+1]) res.push_back(i);
        }
        return res;
    }
};






// A 2

