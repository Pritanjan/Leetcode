// A 1

class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int N = arr.size();
        int one = 0, two = 0;
        for(int i = 0; i < N; i++){
            one = (one ^ arr[i]) & ( ~two );
            two = (two ^ arr[i]) & ( ~one );
        }
        return one;
    }
};






// A 2

