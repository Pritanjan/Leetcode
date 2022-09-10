// https://leetcode.com/problems/candy/discuss/2237022/4-C%2B%2B-oror-with-explanation-oror-Easy-Solution-4

Example  :-
Input : [1,2,87,87,87,2,1]
v1 : [1,1,1,1,1,1,1]
v1 : [1,2,3,1,2,2,1]

v2 : [1,1,1,1,1,1,1]
v2 : [1,2,3,1,3,2,1]


v1 : [1,2,3,1,2,2,1]
v2 : [1,2,3,1,3,2,1]

ans = max(v1,v2) = [1,2,3,1,3,2,1]
Output : 13


//The idea is to visit left to right and give candies based on ratings considering only left neighbor and while visiting from right to left and give candies based on ratings considering only right neighbor children.


class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        
        //create new array v1 & v2 of same size as rating which stores 1 (as each child has given one candy initially).
        vector<int> v1(n,1);
        vector<int> v2(n,1);
        
         //Now, Iterate through array r and make sure if rating is higher than left child, we give 1 more candy to the child than left child
        for(int i=0; i<n-1; i++){
            if(r[i] < r[i+1])
                // v1[i] = v1[i+1] + 1;
                v1[i+1] = v1[i] + 1;
        }
        
        //Reverse iterating through array to make sure if rating is higher than right child we give 1 more candy to child than right child
        for(int i=n-1; i>=1; i--){           
            if(r[i] < r[i-1])
                v2[i-1] = v2[i] + 1;
                // v2[i] = v2[i+1] + 1;
        }
        
        //taking max from both & adding them
        long long int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(v1[i], v2[i]);
        }
        
        return ans;
    }
};

