class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet;
        for(char j : jewels) jewelSet.insert(j);

        int cnt = 0;
        for(char s : stones) {
            if(jewelSet.find(s) != jewelSet.end()) cnt++;
            // if(jewelSet.count(i) )  cnt++;
        }
        return cnt;
    }
};

