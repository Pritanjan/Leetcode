// A 1

class Solution {
public:
    // Check whether the packages can be shipped in less than "days" days with
    // "c" capacity.
    bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }
        int l = maxLoad, r = totalLoad;
        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};






// A 2 Binary Search

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int L = *max_element(weights.begin(), weights.end());
        int R = accumulate(weights.begin(), weights.end(), 0);        
        while(L < R) {
            int mid = L + (R - L) / 2;
            int days = 1;
            int currentWeight = 0;
            
            for(int weight : weights) {
                if(currentWeight + weight > mid) {
                    days++;
                    currentWeight = 0;
                }
                currentWeight += weight;
            }            
            if(days > D) L = mid + 1;
            else R = mid;
        }        
        return L;
    }
};






// A 3  -  DP

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sumWeight = accumulate(weights.begin(), weights.end(), 0);        

        int L = max(maxWeight, sumWeight / D);
        int R = sumWeight;
        while(L < R) {
            int mid = L + (R - L) / 2;
            int days = 1;
            int currentWeight = 0;            
            for(int weight : weights) {
                if(currentWeight + weight > mid) {
                    days++;
                    currentWeight = 0;
                }
                currentWeight += weight;
            }            
            if(days > D) L = mid + 1;
            else R = mid;
        }        
        return L;
    }
};






// A 4
