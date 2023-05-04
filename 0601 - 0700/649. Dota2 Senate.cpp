// APPROACH 1


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dire;
        int n = senate.length();

        for(int i=0; i<n; i++){
            if(senate[i] == 'R') rad.push(i);
            else dire.push(i);
        }

        while(!rad.empty() && !dire.empty()) {
            int r = rad.front();
            rad.pop();

            int d = dire.front();
            dire.pop();

            if(r > d) dire.push(d + n);
            else rad.push(r + n);
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};







// APPROACH 2


