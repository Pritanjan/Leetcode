// A 1 

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> que;
        for(int i=0; i<n; i++) {
            que.push(i);
        }
        
        int time = 0;
        while(!que.empty()) {
            auto front = que.front();
            que.pop();
            time++;
            tickets[front]--;
            if(front == k and tickets[front] == 0) return time;
            if(tickets[front] != 0) que.push(front);
        }
        return time;
    }
};
