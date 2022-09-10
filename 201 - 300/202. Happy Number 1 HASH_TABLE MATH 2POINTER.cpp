// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int,int> temp;
        
        while(n != 1){
            if(temp[n] == 0)
                temp[n]++;
            else
                return false;
        
            int sum = 0;
            while(n!=0){
                int m = n%10;
                sum += pow(m,2);
                n = n/10;
            }
        
            n = sum;
        
        }
        
        return true;
    }
};


// What is the difference between using hash-set or hash-map?

// hash-map can store two values which are the key-value pairs but hash-set can only store one entity which is the key.


// hash-map

// The idea is similar as hase-set. We check the node value to check whether it is in the loop.

// The code is as follow. The time complexity usually is O(1) (the worst may be O(n) due to conflict)

