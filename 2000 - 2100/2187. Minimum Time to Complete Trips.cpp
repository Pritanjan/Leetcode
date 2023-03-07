// APPROACH 1 BRUTE FORCE TLE


class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long trips=0;  // trips would store the trips completed until t time
        int t=1; 
        while(trips<totalTrips){ // if trips==totalTrips, we can break out of the loop 
            for(int i=0;i<time.size();++i){ 
                if(t%time[i]==0) trips++; // if t is divisble by time[i] that means bus i has completed one more trip in time t.
            }
            t++;
        }
        return t-1;
    }
};



// APPROACH 2 BINARY SEARCH


class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long L = 0, R = 100000000000000L;
        while(L < R){
            long long mid = L + (R - L)/2;
            long long trips = 0;

            for(int t : time){
                trips += mid / t;
            }

            if(trips < totalTrips) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};









  
