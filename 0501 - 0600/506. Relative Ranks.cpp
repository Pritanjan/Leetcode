// A 1 

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> idxScore;
        for (int i = 0; i < score.size(); ++i) {
            idxScore.push_back({score[i], i});
        }

        sort(idxScore.rbegin(), idxScore.rend());

        vector<string> ranks(score.size());
        sort(idxScore.rbegin(), idxScore.rend());
        for (int i = 0; i < idxScore.size(); ++i) {
            int idx = idxScore[i].second;
            if (i == 0) ranks[idx] = "Gold Medal";
            else if (i == 1) ranks[idx] = "Silver Medal";
            else if (i == 2) ranks[idx] = "Bronze Medal";
            else ranks[idx] = to_string(i + 1);
        }
        return ranks;
    }
};






// A 2 

