// A 1

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> res(n+1);
        // res.push_back(0);

        for(int i=0; i<n; i++){
            res[i+1] = res[i] + gain[i];
            // res.push_back(res[i] + gain[i]);
        }
        int p = *max_element(res.begin(), res.end());
        return p;
    }
};






// A 2

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;
        for (int g : gain) {
            currentAltitude += g;
            if (currentAltitude > highestAltitude) {
                highestAltitude = currentAltitude;
            }
        }
        return highestAltitude;
    }
};






// A 3 






