// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// STL
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        return arr.size();
    }
};


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
        return arr.size() - count;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 0;
        for(int i=0; i<arr.size() - 1; i++){
            if(arr[i] == arr[i+1])
                count++;
            else
                arr[i+1 - count] = arr[i+1];
        }
        arr.erase(arr.end() - count, arr.end());
        return arr.size();
    }
};




