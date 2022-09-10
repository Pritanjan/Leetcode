// https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long int count = 0;
        
        for(long long int i=0; i<nums.size(); i++){ 
            for(int j=i+1; j<nums.size(); j++){
                long long int L = i+1, R = nums.size();
                long long int sum = nums[i] + nums[j];
                while(L<R){             
                    long long int mid = (L+R)/2;
                    if(nums[mid] < sum)
                        L = mid + 1;
                    else
                        R = mid;
                }
                count += (R-1)-j;
            }
        }
            
        return count;
    }
};


// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
        
//         sort(nums.begin(),nums.end());
//         long long int L = 0, R = nums.size()-1,c=0;
        
//         for(long long int i=2; i<nums.size(); i++){   
//             while(L<R){
//                 long long int mid = (L+R)/2;
//                 if(L+mid > R)
//                     c++;
//                 else if(L+mid < R)
//                     L++;
//                 else
//                     R--;
//             }
//         // }
//         return c;
//     }
// };



