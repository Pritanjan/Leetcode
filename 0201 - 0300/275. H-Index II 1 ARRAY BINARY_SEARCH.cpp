//https://leetcode.com/problems/h-index-ii/

// traverse the array and when you find the first element such 
// that the value of that element is greater than or equal to
// the amount of elements remaining that is our ans so we 
// return the length of array after that point. If no such 
// element exists return 0

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        for(int i=0; i<n; i++){
            if(c[i] >= n-i)
                return n-i; // The first element whose value is more than the length of remaining array. 
//So we return the remaining length which is the answer.
// eg [0,1,3,4,6]  c[2] = 3 >2(length of remaing array) so n-i = length of remaining array + that element
        }
        return 0;
    }
};



       
