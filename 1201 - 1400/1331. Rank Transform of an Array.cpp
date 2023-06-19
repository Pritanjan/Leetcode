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







// APPROACH 2 [  Sorting and Mappin ]

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> Sarr = arr;           // Sarr --> sorted array
        sort(Sarr.begin(), Sarr.end());

        unordered_map<int, int> ump;
        int rank = 1;
        for(int i=0; i<Sarr.size(); i++) {
            if(ump.find(Sarr[i]) == ump.end()) {
                ump[Sarr[i]] = rank;
                rank++;
            }
        }

        for(int i=0; i<arr.size(); i++) {
            arr[i] = ump[arr[i]];
        }
        return arr;
    }
};







// APPROACH 3

