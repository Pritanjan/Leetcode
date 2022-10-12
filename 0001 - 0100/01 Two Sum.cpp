// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> diff;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if( nums[i]+nums[j] == target ){
			diff.push_back(i);
                    	diff.push_back(j);
                    	// diff.push_back(min(nums[i], nums[j]));
                    	// diff.push_back(max(nums[i], nums[j]));  // to get element  
			break;
		}
		else 
			continue;
            }
        }
        return diff;
    }
};





class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end() )
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};



#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
       for(int j=i+1; j<arr.size(); j++){
           if(arr[i] + arr[j] == s){
               vector<int> v;
               v.push_back(min(arr[i], arr[j]));
               v.push_back(max(arr[i], arr[j]));
               ans.push_back(v);
           }
       }
   }
    sort(ans.begin(), ans.end());
    return ans;
}



// If there is more than 1 pair it is used

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
       for(int j=i+1; j<arr.size(); j++){
           if(arr[i] + arr[j] == s){
               vector<int> v;
               v.push_back(min(arr[i], arr[j]));
               v.push_back(max(arr[i], arr[j]));
               ans.push_back(v);
           }
       }
   }
    sort(ans.begin(), ans.end());
    return ans;
}





