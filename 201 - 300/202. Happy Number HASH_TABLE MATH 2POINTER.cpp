// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> temp;
        
        while(n != 1){
            if(temp.find(n) == temp.end())
                temp.insert(n);
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



//
//hash-set
//
//The hash-set solution is very straightforward. For every new data, we check whether it is already in the set. If no, we insert it into the set. If yes, we detect the loop. Only when the node in the loop is "1", the number is happy number.
//
//The code is as follow. The time complexity is O(nlogn) (due to the sort function).
