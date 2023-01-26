class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] arr = new int[n][n];
        for (int[] q : queries) {
            int row1 = q[0];
            int col1 = q[1];
            int row2 = q[2];
            int col2 = q[3];
            
            for (int i = row1; i <= row2; i++) {
                for (int j = col1; j <= col2; j++) {
                    arr[i][j] += 1;
                }
            }
        }
        return arr;
    }
}


