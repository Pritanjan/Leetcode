// APPROACH 1 [ BRUTE FORCE -- TLE]

// Here, At each round, we check if a senator can ban another senator's right or declare victory.
// We continue the simulation until one of the parties wins.
// This approach has a time complexity of O(n^2) in the worst case if implemented naively, but 
// it can be optimized to O(n) using a queue or stack to keep track of the indices of senators
// who still have rights to vote.


class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<int> rights(n, 1); // initialize all senators with rights to vote
        
        while (true) {
            bool radiant_alive = false, dire_alive = false;
            for (int i = 0; i < n; i++) {
                if (rights[i] == 0) continue; // skip senators who have lost their rights
                if (senate[i] == 'R') {
                    dire_alive = true; // check if Dire is still alive
                    if (!radiant_alive) radiant_alive = true; // check if Radiant is still alive
                    else rights[i] = 0; // Radiant announces victory, so ban this senator's right
                }
                else {
                    radiant_alive = true; // check if Radiant is still alive
                    if (!dire_alive) dire_alive = true; // check if Dire is still alive
                    else rights[i] = 0; // Dire announces victory, so ban this senator's right
                }
            }
            if (!radiant_alive) return "Dire"; // all remaining senators belong to Dire
            if (!dire_alive) return "Radiant"; // all remaining senators belong to Radiant
        }
    }
};


// Time complexity: O(N^2), because we may need to iterate over the string n times, and 
// each time we may need to move some senators from the back to the front. However, 
// in practice, the time complexity may be much better.

// Space complexity: O(N),








// APPROACH 2



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


