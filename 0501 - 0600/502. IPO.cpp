class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int i = 0;
        while (k > 0) {
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }
            if (pq.empty()) break;
            
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};


// Time complexity --> O(n log n), where n is the number of projects, due to the sorting step. 
// Space complexity --> O(n), for the vector of projects and O(k) for the priority queue.


// This problem can be solved using a greedy approach. We can first sort the projects by their 
// minimum capital needed to start, in increasing order. 
// Then, we can use a priority queue to keep track of the available projects that 
// we can start with our current capital.

// At each step, we check the projects in the priority queue and choose the one with the
// highest profit that we can afford to start. We then add its profit to our capital and 
// continue until we have either started k projects or there are no more projects available.


// Here is the algorithm:

// 1. Sort the projects by their minimum capital needed to start, in increasing order.
// 2. Initialize a priority queue (max heap) to store the profits of available projects.
// 3. Initialize current capital w to the initial capital.
// 4. For each project i from 1 to n:
//    a. While there are projects available and our current capital is enough to start the project:
//       i. Add the profit of the project to the priority queue.
//       ii. Increment i.
//    b. If we have not started k projects and there are no more projects available, return the 
//       current capital.
//    c. Choose the project with the highest profit from the priority queue and add its profit to
//       the current capital.
//    d. Decrement k.
// 5. Return the final maximized capital.


