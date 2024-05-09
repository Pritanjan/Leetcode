// A 1 - Greedy Sortingg

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long res = 0;
        int cnt = 0;
        for (int i = 0; i < happiness.size(); ++i) {
            res += max(0, happiness[i] - cnt);
            cnt++;
            if(cnt >= k) break;
        }        
        return res;
    }
};





// A2 - Max heap

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Max heap by default
        priority_queue<int> pq; 

        // Push all the happiness values into the priority queue
        for(const auto& h: happiness)
            pq.push(h); 

        long long totalHappinessSum = 0;
        int turns = 0;

        for(int i = 0; i < k; i++) {
            // Add the current highest value to the total happiness sum
            totalHappinessSum += max(pq.top() - turns, 0);

            // Remove the highest value after using it
            pq.pop(); 

            // Increment turns for the next iteration
            turns++; 
        }
        return totalHappinessSum;
    }
};
