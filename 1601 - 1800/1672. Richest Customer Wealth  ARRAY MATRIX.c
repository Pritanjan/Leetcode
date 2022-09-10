//https://leetcode.com/problems/richest-customer-wealth/

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int ans = 0;
    int sum ;
        
    for(int i=0; i<accountsSize; i++){
        sum = 0;
        for(int j=0; j<*accountsColSize; j++){
            sum += accounts[i][j];
        }
        // ans = max(sum, ans);
        if(sum > ans)
            ans = sum;
    }
    return ans;
}
