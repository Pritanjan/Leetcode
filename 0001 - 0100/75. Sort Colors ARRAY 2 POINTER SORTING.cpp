//https://leetcode.com/problems/sort-colors/

APPROACH 1
    
DUTCH NATIONAL FLAG (DNF)
Explanation : -
This programming problem was proposed by Edsger Dijkstra. The flag of the Netherlands consists 
of three colors: white, red, and blue. The task is to randomly arrange balls of red, white, and 
blue in such a way that balls of the same color are placed together. For DNF (Dutch National Flag),
we sort an array of 0, 1, and 2's in linear time that does not consume any extra space. We have 
to keep in mind that this algorithm can be implemented only on an array that has three unique 
elements.

ALGORITHM : -
Take three-pointers, namely - L , mid , high.
We use L and mid pointers at the start, and the R pointer will point at the end of the given array.

CASES : -
If array [mid] =0 , then swap array [mid] with array [L] and increment both pointers once.
If array [mid] = 1 , then no swapping is required. Increment mid pointer once.
If array [mid] = 2 , then we swap array [mid] with array [R] and decrement the high pointer once.

    
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


// APPROACH 3

class Solution {
public:
    void sortColors(vector<int>& a) {
        int L = 0;
        int n = a.size();
        int R = n-1;
        int mid = 0;
        
        while(mid <= R ){
            if(a[mid] == 0){
                swap(a[L], a[mid]);
                L++;
                mid++;
                // break;
            }
            
            else if(a[mid] == 1){
                mid++;
                // break;
            }
            
            else{
                swap(a[mid], a[R]);
                R--;
                // break;
            }
        }
        // return 0;
    }
};



    

