// APPROACH 1 BRUTE FORCE - TLE

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        int mi = INT_MAX;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                mi = min(abs(arr[i] - arr[j]), mi);
            }
        }

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(abs(arr[i] - arr[j]) == mi) {
                    // res.push_back({arr[i], arr[j]});
                    if(arr[i] < arr[j]) res.push_back({arr[i], arr[j]});
                    else res.push_back({arr[j], arr[i]});
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};






// APPROACH 2 first sort & then traverse

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int mi = INT_MAX;
        for(int i=0; i<n-1; i++) {
            mi = min(abs(arr[i] - arr[i+1]), mi);
        }

        vector<vector<int>> res;
        for(int i=0; i<n-1; i++) {
            if(abs(arr[i] - arr[i+1]) == mi) 
               res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};





// APPROACH 3 2 POINTER

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int mi = INT_MAX;
        int L = 0;
        int R = 1;

        while(R < n) {
            int absDiff = abs(arr[L] - arr[R]);
            if(absDiff < mi) {
                mi = absDiff;
                res.clear();
                res.push_back({arr[L], arr[R]});
            } 
            else if(absDiff == mi) {
                res.push_back({arr[L], arr[R]});
            }

            L++;
            R++;
        }
        return res;
    }
};







// APPROACH 4



