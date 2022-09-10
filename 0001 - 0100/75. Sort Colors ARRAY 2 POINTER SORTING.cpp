//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& a) {
        // sort(nums.begin(),nums.end());
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
//             if(a[mid] == 0){
//                 swap(a[L], a[mid]);
//                 L++;
//                 mid++;
//                 // break;
//             }
            
//             if(a[mid] == 1){
//                 mid++;
//                 // break;
//             }
            
//             else{
//                 swap(a[mid], a[R]);
//                 R--;
//                 // break;
//             }
        }
        // return 0;
    }
};



