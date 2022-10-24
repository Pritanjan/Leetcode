// Recursion

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


