//https://leetcode.com/problems/course-schedule-iii/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(),[](auto &a, auto &s){return a[1] < s[1];});
        priority_queue<int> pq;
        int time = 0;
        
        // for(int i=0; i<c.size(); i++)
        for(auto c : courses)
        {
        	// chekc if we consider the curr course
            if(c[0] <= c[1])
            {
                // curr course can be completed within last day
                if(c[0] + time <= c[1])
                {
                    pq.push(c[0]);
                    time +=  c[0];
                    //if yes, add the new course and update the time
                }
                else
                // if exceeds deadline, swap it with the biggest duration from the ones taken up
                // swap should reduce the time taken till now
                {
                    if(pq.top() > c[0])
                    {
                        time -= pq.top();
                        pq.pop();
                        time += c[0];
                        pq.push(c[0]);
                    }
                        
                }
            }
        }
        // all taken up courses present in priority queue
        return pq.size();
    }
};


// S1 --> sort the array based on the last day
// s2 --> Take Priority_queue to store the durations (we can easily find the maximum at any time)
// s2 --> Iterate over input & try to maximize the endtime while maximizing the courses.
// s3 --> Return - size of pq
