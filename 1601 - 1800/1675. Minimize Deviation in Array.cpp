// https://www.geeksforgeeks.org/minimize-deviation-of-an-array-by-given-operations/


// APPROACH 1


// The function first creates an empty set s to store the numbers.
// It then iterates through the input vector A, and for each number in A,
// it checks whether it is even or odd. 
// If it is even, it inserts the number directly into the set s. 
// If it is odd, it multiplies the number by 2 and inserts the result into the set s. 
// This ensures that all numbers in the set s are even.


// The function then initializes the difference 'diff' as the difference between 
// the largest and smallest numbers in the set s. 
// It then enters a loop that continues as long as the set s is not empty and
// the largest element in the set s is even. 
// In each iteration of the loop, it removes the largest element maxEl from the set s, 
// divides it by 2, and inserts the result back into the set s. 
// It then updates the value of diff as the minimum of its current value and the
// difference between the largest and smallest numbers in the set s.


// Finally, the function returns the value of diff.


// This implementation is similar in approach to the previous implementation using a priority queue, 
// but it uses a set instead. The advantage of using a set is that it automatically
// keeps the elements in sorted order,
// so we don't need to maintain a separate priority queue.
// However, removing and inserting elements in a set takes O(log n) time, 
// whereas it takes O(log n) time to remove the maximum element and
// O(1) time to insert a new element in a priority queue.
// Therefore, the time complexity of this implementation is O(n log n) in the worst case.
// Auxiliary Space : O(N) 




class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        set<int> s;
        int N = A.size();
        
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 0)
                s.insert(A[i]);
            else
                s.insert(2 * A[i]);
        }
 
        int diff = *s.rbegin() - *s.begin();
 
        while((int)s.size() && *s.rbegin() % 2 == 0) {
            int maxEl = *s.rbegin();
            s.erase(maxEl);
            s.insert(maxEl / 2);
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        return diff;
    }
};






// APPROACH 2


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_val = INT_MAX;
        
        for(int n : nums) {
            if(n % 2 == 1) n *= 2;
            min_val = min(min_val, n);
            pq.push(n);
        }

        int ans = INT_MAX;
        while (true) {
            int curr = pq.top();
            pq.pop();
            ans = min(ans, curr - min_val);
            if (curr % 2 == 1) break;
            min_val = min(min_val, curr / 2);
            pq.push(curr / 2);
        }
        return ans;
    }
};



