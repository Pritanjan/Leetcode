// APPROACH 1 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() <= 1) return {nums};
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto a = permute(v);
            
            for(int j=0; j<a.size(); j++){
                vector<int> v1 = a[j];
                v1.insert(v1.begin(), nums[i]);
                ans.push_back(v1);
            }
        }
        return ans;
    }
};






// APPROACH 2  Recursive

class Solution {
public:
    vector<vector<int>> ans;
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx >= n){
            ans.push_back(nums);
            return ;
        }
        for(int i=idx; i<n; i++){
            swap(nums[idx], nums[i]);
            permute(idx+1, nums);
            swap(nums[idx], nums[i]); 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(0, nums);
        return ans;
    }
};







// APPROACH 3

class Solution {
public:
    vector<vector<int>> ans;
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx = n){
            ans.push_back(nums);
        }
        else{
            for(int i=idx; i<n; i++){
                swap(nums[idx], nums[i]);
                permute(idx+1, nums);
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(ans, nums, 0);
        return ans;
    }
};






```javascript []
console.log('Hello world!')
```
```C++ []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
