// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        auto num = to_string(n);
        next_permutation(num.begin(), num.end());
        auto ans=stoll(num);
        return (ans <= n or ans > INT_MAX) ? -1 : ans;
    }
};



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
long long int bobsHomework(int n)
{
    // Write your code here. 
    string num=to_string(n);
    nextPermutation(num);
    size_t ans=stoll(num);
    return (ans<=n)?-1:ans;
}








 
