// APPROACH 1 [ TLE ]

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=0; j<n; j++){
                if(arr[i] > arr[j]) {
                    st.insert(arr[j]);
                }
            }
            res.push_back(st.size() + 1);
        }
        return res;
    }
};



// T.C. --> O(N^2)
// S.C. --> O(N)




