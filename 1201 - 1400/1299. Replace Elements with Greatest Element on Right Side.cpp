class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n = a.size();
          vector<int> ans;
        int mx = a[n-1];
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--){
          ans.push_back(mx);
            if(a[i]>=mx){
               
                mx = a[i];
            }

            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int ma = -1;
        for(int i=nums.size()-1; i>=0; --i)
            ma = max(ma, exchange(nums[i], ma));
        return nums;
    }
};



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp;
        int ma = -1;
        
        for(int i=arr.size()-1; i>=0; i--){
            temp = arr[i];
            arr[i] = ma;
            ma = max(ma,temp);
        }
        return arr;
    }
};

// temp      1   6   4    5    18    17
// arr[i]   -1   1   6    6    6     18
// ma        1   6   6    6    18    18
