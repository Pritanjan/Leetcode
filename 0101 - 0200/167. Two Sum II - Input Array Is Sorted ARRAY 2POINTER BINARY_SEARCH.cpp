// APPROACH 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        while(L < R){
            if(nums[L] + nums[R] == target){
                return {L+1, R+1};
            }
            else if(nums[L] + nums[R] > target)
                R--;
            else
                L++;
                
        }
        return {};
    }
};









// APPROACH 2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size()-1; i++){
            int L = i+1;
            int R = nums.size();      
            while(L < R){
                int mid = L + (R - L)/2;
                if(nums[mid] == target - nums[i]) return {i+1, mid+1};
                else if(nums[mid] >= target - nums[i]) R = mid;
                else L = mid + 1;
            }

            if(L != nums.size() and nums[L] == target - nums[i]) return {i+1, L+1};
        }
        
        return {};
    }
};






// APPROACH 3

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
            int l=i+1;
            int h=numbers.size()-1;
            while(h>=l){
                int mid=l+(h-l)/2;
                if(numbers[mid]+numbers[i]==target){
                    return {i+1,mid+1};
                }
                else if(numbers[mid]+numbers[i]>target){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return {-1,-1};
    }
};


// OR 

class Solution {
public:
    int bs(vector<int> &v, int ind, int target){
        int L = ind;
        int R = v.size() - 1;
        int ans = 0;
        while(L <= R) {
            int mid = L + (R - L)/2;
            if(v[mid]==target) {
                ans = mid;
                break;
            }
            else if(v[mid] >= target) R = mid - 1;
            else L = mid + 1;
        }

        return ans;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> v;
        for(int i=0; i<n; i++) {
            int ans = bs(numbers, i+1, target-numbers[i]);
            if(ans) {
                v.push_back(i+1);
                v.push_back(ans+1);
            }
        }
        return v;
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>r;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(numbers[i]+numbers[j]<target){
                    break;
                }
                else if(numbers[i]+numbers[j]==target){
                    r.push_back(j+1);
                    r.push_back(i+1);
                    return r;
                    cout<<r[0]<<r[1];
                }
                else{
                    continue;
                }
            }
        }
        return r;

    }
};

