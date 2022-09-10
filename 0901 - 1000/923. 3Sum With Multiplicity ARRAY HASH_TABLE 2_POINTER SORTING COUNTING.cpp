// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        long count = 0;
        
        for(int i=1; i<n-1; i++){
            int x = arr[i];
            int L,R;
            int a[1000] = {0};
            
            for(int R=i+1; R<n; R++ ){
                a[arr[R]]++;
            }
            for(int j=0; j<i; j++){
                int sum = target - x - arr[j];
                if(sum>=0){
                    if(a[sum]>0)
                        count += a[sum];
                }
            }
        }
        return count%(1000000007);
    }
};
