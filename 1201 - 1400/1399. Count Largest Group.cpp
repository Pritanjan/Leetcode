class Solution {
public:
    int countLargestGroup(int n) {
        // To maintain the cnt of all the no i.e. upto 36
        vector<int> cnt(37);
        int max_size = 0;
        for(int i=1; i<=n; i++)
            max_size =  max(++cnt[digSum(i)], max_size);
        
        int ans = 0;
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i] == max_size)
                ans++;
        }
        return ans;
    }
    
    // find the sum of digit we encounter
    int digSum(int n){
        int sum = 0;
        
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
};


// 9999 --> 36



