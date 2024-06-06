// A 1 

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> countMap;
        for (int card : hand) countMap[card]++;

        for(auto& [card, count] : countMap) {
            if (count > 0) {
                for (int i = 1; i < groupSize; ++i) {
                    countMap[card + i] -= count;
                    if (countMap[card + i] < 0) {
                        return false; // If we can't form a group of consecutive cards, return false
                    }
                }
            }
        }
        return true;
    }
};
