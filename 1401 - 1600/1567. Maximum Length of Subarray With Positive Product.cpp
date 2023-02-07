// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0049%20070223%20Length%20of%20the%20longest%20subarray%20with%20positive%20product.cpp

class Solution {
public:
    // Function to return the length of the
    //longest subarray with ppositive product
    int getMaxLen(vector<int> &arr){
        int N = arr.size();
        int Pos = 0, Neg = 0, res = 0;
        for (int i=0; i<N; i++){
            if(arr[i] == 0) {
                Pos = Neg = 0;
            }
            else if(arr[i] > 0){
                Pos += 1;
                if (Neg != 0) {
                    Neg += 1;
                }
                res = max(res, Pos);
            }
            else{
                swap(Pos, Neg);
                Neg += 1;
                if(Pos != 0) {
                    Pos += 1;
                }
                res = max(res, Pos);
            }
        }
        return res;
    }
};



// Time Complexity: O(N)
// Auxiliary Space: O(1)



