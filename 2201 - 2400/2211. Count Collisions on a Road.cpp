// APPROACH 1

// Traverse from left to right, 
// Record the status and number of vehicles that may collide on the left side of the vehicle, 
// when a collision occurs, accumulate the number of collisions, and update the status of the
// left vehicle.
// Only when the state of the vehicle on the Rleft, 
// it is possible for multiple consecutive Rvehicles to collide with the current vehicle, 
// so the number of multiple consecutive Rvehicles is counted by count, and the count is recounted 
// when a collision occurs.



class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        char left = '\0';
        int count = 0;
        for(char ch : directions) {
            if(left == '\0') {
                left = ch;
                if(ch == 'R'){
                    count++;
                }
            }
            else{
                if(ch == 'L'){
                    if(left == 'R'){
                        collisions += count + 1;
                        left = 'S';
                        count = 0;
                    }else if(left == 'S'){
                        left = 'S';
                        collisions += 1;
                    }
                }else if(ch == 'R'){
                    left = 'R';
                    count += 1;
                }else{
                    if(left == 'R'){
                        collisions += count;
                        count = 0;
                    }
                    left = 'S';
                }
            }
        }
        return collisions;
    }
};
