// A1 -  Recursion

class Solution {
private:
    void f(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=idx; i<arr.size(); i++){
            ds.push_back(arr[i]);
            f(i+1, arr, ds, ans);            
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(0, arr, ds, ans);
        return ans;
    }
};




















// Subset Sums
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
public:
    void f(int idx, int sum, vector<int>& arr,  vector<int> &ans){
        if(idx == arr.size()){
            ans.push_back(sum);
            return ;
        }
        // pick element
        f(idx+1, sum + arr[idx], arr, ans);
        // Not pick element
        f(idx+1, sum, arr, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        f(0, 0, arr, ans);        
        sort(ans.begin(), ans.end());
        return ans;
    }
};






