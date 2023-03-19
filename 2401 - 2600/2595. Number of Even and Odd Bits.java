class Solution {
    public int[] evenOddBit(int n) {
        int[] answer = new int[2];
        int i = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                if (i % 2 == 0) {
                    answer[0]++;
                } else {
                    answer[1]++;
                }
            }
            i++;
            n >>= 1;
        }
        return answer;
    }
}


