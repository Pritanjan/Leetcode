// APPROACH 1

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        
        int n = stones.size();
        // maximum value
        int maxd = max(stones[n - 1] - stones[1], stones[n-2] - stones[0]) - n + 2;
        int mind = 10001;
        
        // minimum value
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && stones[j + 1] - stones[i] < n) j++;
            
            int cost = n - (j - i + 1);
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) cost = 2;
            
            mind = min(mind, cost);
        }
        
        return {mind, maxd};
    }
};


// APPROACH 2


class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxstep = (stones[n-1]-stones[0]+1-n)-min(stones[n-1]-stones[n-2]-1,stones[1]-stones[0]-1);
        int minstep = maxstep,i = 0,j = 0,step = 0;
        for(;i < n;i++){
            while(j + 1 < n && stones[j + 1] - stones[i] + 1 <= n)
                ++j;
            step = n - (j - i + 1);
            if(j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                step = 2;
            minstep = min(minstep,step);
        }
        return {minstep,maxstep};
    }
};
