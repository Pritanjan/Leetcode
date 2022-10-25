class Solution {
private:
    void f(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans){
        ans.push_back(ds);      // to print empty set
        for(int i=idx; i<arr.size(); i++){
            if(i != idx and arr[i] == arr[i-1])   // if duplicate element if found then ignore it 
                continue;
            ds.push_back(arr[i]);   // else push the element into the ds 
            f(i+1, arr, ds, ans);   // recursive call the function
            ds.pop_back();          // remove the first element form the top of the array
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;    // to store all the required pair 
        vector<int> ds;             // creating the pair
        
        sort(arr.begin(), arr.end());   // sorting the array as we can ignore the element the duplicate the pair
        f(0, arr, ds, ans);         
        
        return ans;
    }
};

