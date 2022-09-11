// https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/
// https://leetcode.com/problems/most-frequent-even-element/

// Explanation
// https://www.studytonight.com/c-programs/c-program-to-find-the-maximum-repeating-element-in-an-array


// APPROACH 1
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0)
                v.push_back(nums[i]);
        }
        
        sort(v.begin(), v.end());
        
        // for(int i=0; i<nums.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        
        if(v.size() == 0)
            return -1;
        
        int max_freq = 1;
        int ans = v[0];
        int cnt = 1;
        
        for(int i=1; i<v.size(); i++){
            if(v[i] == v[i-1])
                cnt++;
            else{
                if (cnt > max_freq) { 
                    max_freq = cnt; 
                    ans = v[i - 1]; 
                } 
                cnt = 1;
            }
        }    
        if(cnt > max_freq){
            max_freq = cnt;
            ans = v[v.size() - 1];
        }
        return ans;
    }
};


// APPROACH 2

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        // vector<int> v;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] % 2 == 0)
        //         v.push_back(nums[i]);
        // }
        
        map<int, int> ump;
        for(int i=0; i<nums.size(); i++){
            ump[nums[i]]++;
        }
        
        int max_cnt = 0;
        int ans = -1;
        for(auto i : ump){
            if (i.first % 2 == 0 and max_cnt < i.second) {
                ans = i.first;
                max_cnt = i.second;
            }
        }
        return ans;
    }
};





