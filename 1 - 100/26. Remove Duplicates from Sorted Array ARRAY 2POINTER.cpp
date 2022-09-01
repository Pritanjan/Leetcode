// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == arr[i-1])
                count++;
            else
                arr[i-count] = arr[i];
        }
        //APPROACH 1
        // return arr.size() - count;
        
        // APPROACH 2
        arr.erase(arr.end() - count, arr.end());
        return arr.size();
        
        // APPROACH 3 STL 
        // arr.erase(unique(arr.begin(),arr.end()),arr.end());
        // return arr.size();
    }
};
