// APPROACH 1

// Traverse from left to right, 
// Record the status and number of vehicles that may collide on the left side of the vehicle, 
// when a collision occurs, accumulate the number of collisions, and update the status of the
// left vehicle.
// Only when the state of the vehicle on the Rleft, 
// it is possible for multiple consecutive Rvehicles to collide with the current vehicle, 
// so the number of multiple consecutive Rvehicles is counted by count, and the count is recounted 
// when a collision occurs.



// 1 Initialize variables:
//    collisions: a counter for the number of collisions. Initially set to 0.
//    left: a variable to store the previous character. Initially set to '\0' (null character).
//    count: a counter for the number of consecutive 'R' characters. Initially set to 0.

// 2. Loop through each character in the input string directions:
//    If left is equal to the null character, set left to the current character ch.
//    If ch is 'R', increment count by 1.
//    If ch is 'L':
//       If left is 'R', increment collisions by the value of count plus 1, set left to 'S', and reset count to 0.
//       If left is 'S', increment collisions by 1 and set left to 'S'.
//    If ch is 'S':
//       If left is 'R', increment collisions by the value of count and reset count to 0.
//       Set left to 'S'.

// 3. Return the total number of collisions stored in collisions.


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


// The time complexity of this solution is O(n), where n is the length of the input string.
// This is because the code performs a linear scan of the string and updates the variables
// left, count, and collisions for each character in the string.

// The space complexity of this solution is O(1), 
// as it only uses a constant amount of memory to store the variables left, count, and collisions.



// APPROACH 2

// only the leftmost continuum Land the rightmost continuum Rwill not collide. 
// In other cases, Lboth Rwill collide. Find the starting point and end point of the collision, 
// and count the number of collisions.



// 1. Initialize variables:
//    collisions: a counter for the number of collisions. Initially set to 0.
//    left: an index for the first character in the string that is not 'L'.
//    right: an index for the last character in the string that is not 'R'.

// 2. Find the first and last characters that are not 'L' or 'R':
//    While left is less than the length of directions and the character at left is 'L', increment left by 1.
//    While right is greater than or equal to 0 and the character at right is 'R', decrement right by 1.

// 3. Loop through the characters in the directions string from left to right (inclusive):
//    If the current character is not 'S', increment collisions by 1.

// 4. Return the total number of collisions stored in collisions.

class Solution {
public:
    int countCollisions(std::string directions) {
        int collisions = 0;
        int left = 0;
        int right = directions.length() - 1;
        while (left < directions.length() && directions[left] == 'L') {
            left += 1;
        }
        while (right >= 0 && directions[right] == 'R') {
            right -= 1;
        }

        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                collisions += 1;
            }
        }

        return collisions;
    }
};


// The time complexity of this solution is O(n), n is the length of the input string directions. 
// This is because the code performs two linear scans of the string 
// to find the first and last characters that are not 'L' or 'R', 
// and then another linear scan of the string from left to right (inclusive) to count 
// the number of collisions.

// The space complexity of this solution is O(1),
// as it only uses a constant amount of memory to store the variables collisions, left, and right.

