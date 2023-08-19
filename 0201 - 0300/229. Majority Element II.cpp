// Similar question LC 169
// APPROACH 1 Brute Force

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> um;
        // map<int, int> um;  //BOTH WORKS
        for(auto i : nums) um[i]++;
        
        for(auto it : um) {
            if(it.second > n/3) v.push_back(it.first);
        }            
        return v;
    }
};






// APPROACH 2 Boyer-Moore Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1;
        int cnt1 = 0, cnt2 = 0;

        // Finding potential candidates using the Boyer-Moore algorithm
        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
            else if(cnt1 == 0) {
                candidate1 = num;
                cnt1 = 1;
            } 
            else if(cnt2 == 0) {
                candidate2 = num;
                cnt2 = 1;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Counting occurrences of the potential candidates
        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
        }

        // Checking which candidates meet the threshold
        vector<int> res;
        if(cnt1 > nums.size() / 3) res.push_back(candidate1);
        if(cnt2 > nums.size() / 3) res.push_back(candidate2);
        return res;        
    }
};

