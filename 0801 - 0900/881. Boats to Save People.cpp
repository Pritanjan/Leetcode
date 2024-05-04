// A 1 

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());     // Sort the array in ascending order
        int L = 0;
        int R = people.size() - 1;      // Initialize pointers to the start and end of the array

        int cnt = 0;        // Initialize the number of boats to 0
        while(L <= R) {     // While there are people left to transport
            // int mid = (L + R) / 2;
            
            // If the sum of the weights of the two people is less than or equal to the limit
            if(people[L] + people[R] <= limit) L++;

            cnt++;      // Increment the number of boats required
            R--;        // Move the right pointer to the left
        }
        return cnt;     // Return the number of boats required
    }
};






// A 2 

