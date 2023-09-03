// A 1

// Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// Find the largest index l > k such that nums[k] < nums[l].
// Swap nums[k] and nums[l].
// Reverse the sub-array nums[k + 1:].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        for(i=n-2; i>=0; i--){
            if(nums[i+1] > nums[i]) break;
        }
        
        if(i < 0) reverse(nums.begin(), nums.end() );       
        else {
            for(j=n-1; j>=0; j--){
                if(nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }       
    }
};




// OR

class Solution {
public:        
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;

        // Find the first decreasing element from the right
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;

        if(i >= 0) {
            // Find the next greater element than nums[i]
            int j = n-1;
            while(j > i && nums[j] <= nums[i]) j--;
            
            // Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        // Reverse the suffix starting from i+1
        reverse(nums.begin()+i+1, nums.end());
    }
};





// A 2

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         next_permutation(nums.begin(), nums.end());
    }
};





// A 3















// 2ND QUESTION PRINTING NEXT PERMUTATION OF A GIVEN NUMBER
// https://www.codingninjas.com/codestudio/problems/bob-homework_2656187?topList=amazon-sde-challenge

#include<bits/stdc++.h>
void nextPermutation(string &nums){
    int i;
    for(i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1])
            break;
    }
   int j=nums.size()-1;
   if(i>=0){
       while(nums[j]<=nums[i])j--;
       swap(nums[j],nums[i]);
   }
   reverse(nums.begin()+i+1,nums.end());
}

long long int bobsHomework(int n) {
    // Write your code here. 
    string num=to_string(n);
    nextPermutation(num);
    size_t ans=stoll(num);
    return (ans<=n)?-1:ans;
}




