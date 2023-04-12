// APPROACH 1


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0) v.push_back(nums[i]);
        }
        
        sort(v.begin(), v.end());
        if(v.size() == 0) return -1;
        
        int max_freq = 1;
        int ans = v[0];
        int cnt = 1;
        
        for(int i=1; i<v.size(); i++){
            if(v[i] == v[i-1]) cnt++;
            else { 
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











// APPROACH 1

// 1. unordered_map is used to count the frequency of even numbers,
// 2. custom comparison function cmp is used to sort the map by frequency in ascending order, 
//    with ties broken by the larger number.
// 3. Finally, we use max_element to find the most frequent even number in the map.

class Solution {
public:    
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (num % 2 == 0) {
                count[num]++;
            }
        }
        auto cmp = [](const auto& a, const auto& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        };
        auto it = max_element(count.begin(), count.end(), cmp);
        return it == count.end() ? -1 : it->first;
    }
};


// OR


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            if (x % 2 == 0) {
                count[x]++;
            }
        }
        int res = -1, ct = 0;
        for (auto &p : count) {
            if (res == -1 || p.second > ct || p.second == ct && res > p.first) {
                res = p.first;
                ct = p.second;
            }
        }
        return res;
    }
};


// OR


// Note that we use an unordered_map to count the frequency of all numbers, and 
// then create a separate vector of pairs for even numbers with their respective counts
// then a custom comparison function cmp to sort the vector by frequency in ascending order,
// with ties broken by the larger number. 
// Finally, we use max_element to find the most frequent even number in the vector.

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        vector<pair<int, int>> v;
        for(auto& p : count) {
            if (p.first % 2 == 0) {
                v.emplace_back(p.first, p.second);
            }
        }

        if(v.empty()) return -1;
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        };

        auto it = max_element(v.begin(), v.end(), cmp);
        return it->first;
    }
};





// APPROACH 2


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int Max=0, r=-1;
        unordered_map<int, int> M;
        for(auto &x: nums)
            if((x&1)==0)
                if(++M[x] > Max){
                    Max = M[x];
                    r = x;
                }
                else if(M[x] == Max) r = min(r, x);
        return r;
    }
};






// APPROACH 3

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {   
        vector<int> freq(50001, 0);
        int k = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                int p = num / 2;
                freq[p]++;
                if (freq[p] > freq[k] || (freq[p] == freq[k] && p < k)) {
                    k = p;
                }
            }
        }
        return freq[k] == 0 ? -1 : 2 * k;
    }
};







// APPROACH 4


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        short count[100003] = { 0 };
        int max = -1;
        int v = -1;

        for(auto&& n : nums) {
            if(!(n&1)) {
                ++count[n];
                if(count[n] > max) {
                    max = count[n];
                    v = n;
                }
                else if(count[n] == max) {
                    v = min(v, n);
                }
            }
        }
        
        return v;
    }
};







// APPROACH 5

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {   
        vector<vector<int>> freq;
        freq.push_back({1, -1});
        for (auto& p : unordered_map<int, int>({})) {
            int k = p.first, v = p.second;
            if (k % 2 == 0) {
                freq.push_back({-v, k});
            }
        }
        sort(freq.begin(), freq.end());
        return freq[0][1];
    }
};



// OR


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {   
        int ans = -1;
        int cnt = 0;
        for(auto& p : unordered_map<int, int>({})) {
            int k = p.first, v = p.second;
            if (k % 2 == 0 && (v > cnt || (v == cnt && k < ans))) {
                ans = k;
                cnt = v;
            }
        }
        return ans;
    }
};


// APPROACH 9

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int count[50001]={0};
        int res=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(nums[i]%2==0){
                int index=nums[i]/2;
                count[index]++;
                if(count[index]>=res){
                    if(res==count[index]){
                        ans=min(ans,nums[i]);
                    }else{
                        res=count[index];
                        ans=nums[i];
                    }
                }
            }
        }
        return res==0? -1:ans;
    }
};


