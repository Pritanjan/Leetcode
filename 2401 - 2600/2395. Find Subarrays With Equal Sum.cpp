// APPROACH 1


class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        for(int i=0; i<nums.size()-2; ++i){
            for(int j=i+1; j<nums.size()-1; ++j) {
                if(nums[i] + nums[i+1] == nums[j] + nums[j+1]) return true;
            }
        }            
        return false;
    }
};



// OR


class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        for(int i {0}; i < nums.size() - 2; ++i){
            int sum {nums[i] + nums[i+1]};
            for(int j {i+1}; j < nums.size() - 1; ++j){
                if(nums[j] + nums[j+1] == sum)
                    return true;
            }
        }
        return false;
    }
};




class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]; 
            count++;     
            if(mp.find(sum) != mp.end()) return true;
            
            if(count == 2) {
                mp[sum]++;
                cout << sum << endl;
                sum = nums[i];
                count = 1;
            }
            // cout<<sum<<endl;
        }
        return 0;
    }
};




class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=1;i<n;i++){
            int sum = nums[i]+nums[i-1];
            mp[sum]++;
            if(mp[sum]>1) return true;
        }
        return false;
    }
};



class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int> sum;
        for(int i=0; i<nums.size()-1; i++){
            sum.push_back(nums[i] + nums[i+1]);
            // sum[i] = (nums[i] + nums[i+1]);
        }

        sort(sum.begin(), sum.end());
        for(int i=0; i<sum.size()-1; i++){
            if(sum[i] == sum[i+1]) return true;
        }
        return false;
    }
};



class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int>v;
        for(int i=0; i<nums.size()-1; i++) {
            v.push_back(nums[i]+nums[i+1]);
        }
        
        for(int i=0; i<v.size(); i++) {
            for(int j=i+1; j<v.size(); j++) {
                if(v[i] == v[j]) return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size()-1);
        for(int i=0; i<nums.size()-1; i++) {
            ans[i] = nums[i] + nums[i+1];
        }
        
        int mx=INT_MIN,count=0;
        map<int, int> mp;
        for(auto i : ans) mp[i]++;

        for(auto i : mp) {
            if(i.second > 1) return true;
        }        
        return false;
    }
};






class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;

        unordered_set<int> ust;
        bool exists;
        int curr_sum;

        for(int i=0; i<len-1; i++) {
            curr_sum = nums[i] + nums[i+1];
            exists   = (ust.find(curr_sum) != ust.end());

            if(exists) return true;
            ust.insert(curr_sum);
        }
        return false;
    }
};



class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> ust;
        for(int i=1; i<nums.size(); ++i)
        if(!ust.insert(nums[i - 1] + nums[i]).second) return true;
        return false;
    }
};

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> ust;
        for(int i=1; i<nums.size(); i++) {
            int sum = nums[i] + nums[i-1];
            
            if(ust.find(sum) != ust.end()) return true;
            ust.insert(sum);
        }
        return false;
    }
};





class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=1; i<nums.size(); i++) {
            int sum = nums[i] + nums[i-1];

            if(st.count(sum)) return true;
            else st.insert(sum);
        }
        return false;
    }
};




class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> st;

        for(int i=0; i<nums.size()-1; i++)
        st.insert(nums[i] + nums[i+1]);
        
        for(auto i : st) cout << i << endl;
        
        if(st.size() == nums.size()-1) return false;
        return true;        
    }
};




