// A 1

class Solution {
public:
    int convertHrsToMin(string& time) {
        int hrs = stoi(time.substr(0, 2));
        int mint = stoi(time.substr(3, 2));

        return hrs * 60 + mint;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> mint;
        for (string& time : timePoints) {
            mint.push_back(convertHrsToMin(time));
        }

        sort(mint.begin(), mint.end());

        int miDif = INT_MAX;

        for (int i = 1; i < mint.size(); ++i) {
            miDif = min(miDif, mint[i] - mint[i - 1]);
        }

        int wrapAroundDiff = (1440 + mint[0] - mint.back()) % 1440;
        miDif = min(miDif, wrapAroundDiff);
        return miDif;
    }
};
