//https://leetcode.com/problems/sort-colors/


// APPROACH 1

class Solution {
public:
    void sortColors(vector<int>& a) {
        int L = 0;
        int n = a.size();
        int R = n-1;
        int mid = 0;
        
        while(mid <= R ){
            switch(a[mid]){
                case 0 : {
                    swap(a[L], a[mid]);
                    L++;
                    mid++;
                    break;
                }
                case 1 : {
                    mid++;
                    break;
                }
                case 2 : {
                    swap(a[mid], a[R]);
                    R--;
                    break;
                }   
            }
        }
    }
};


// APPROACH 2 STL

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};





    

