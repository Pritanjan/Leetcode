// A 1 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        for(int num : nums) {
            xorSum ^= num;
        }

        int tgt = xorSum ^ k;
        int op = 0;
        while(tgt > 0) {
            if (tgt & 1) {
                op++;
            }
            tgt >>= 1;
        }
        return op;
    }
};
