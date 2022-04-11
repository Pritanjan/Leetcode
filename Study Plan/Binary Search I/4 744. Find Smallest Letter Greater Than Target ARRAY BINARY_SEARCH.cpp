// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int L = 0;
        int R = letters.size();
        int mid;
        
        while (L < R){
            int mid = (L+R)/2;
            if(letters[mid] <=target)
                L = mid + 1;
            else 
                R = mid ;
            
        }
        if(letters[L] > target)
            return letters[L];
        else
           return letters[0];
        
    }
};
