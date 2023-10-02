// A 1

class Solution {
public:
    bool winnerOfGame(string color) {
        int n = color.size();
        int cntA = 0;
        int cntB = 0;
        for(int i=1; i<n-1; i++) {
            if(color[i-1] == 'A' and color[i] == 'A' and color[i+1] == 'A') cntA++;
            else if(color[i-1] == 'B' and color[i] == 'B' and color[i+1] == 'B') cntB++;
        }
        // return cntA > cntB;
        if(cntA - cntB > 0) return 1;
        return 0;
    }
};
