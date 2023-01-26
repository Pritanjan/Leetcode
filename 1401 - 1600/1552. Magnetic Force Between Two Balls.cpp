// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0025%20031122%20Aggressive%20Cows.cpp
// https://practice.geeksforgeeks.org/problems/aggressive-cows/1

// SAME AS Aggressive Cows

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int L = 0;
        int R = position[n-1] - position[0];
        
        int ans = 0;
        
        while(L <= R){
            int mid = L + (R - L)/2;
            int cow = 1;
            int end = position[0];
            
            for(int i=1; i<n; i++){
                if(position[i] - end >= mid){
                    cow++;
                    end = position[i];
                }
            }
            if(cow >= m){
                ans = mid;
                L = mid + 1;
            }else{
                R = mid - 1;
            }
        }
        return ans;
    }
};




