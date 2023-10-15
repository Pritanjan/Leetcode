// A 1

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int ans = 0;        
        for(int i=1; i<n-1; ){
            if(arr[i] > arr[i+1] and arr[i-1] < arr[i]) {
                int cnt = 0;
                int j = i;
                while(j > 0 and arr[j] > arr[j-1]){
                    cnt++;
                    j--;
                }
                while(i < n-1 and arr[i] > arr[i+1]){
                    cnt++;
                    i++;
                }
                ans = max(ans, cnt);
            }
            else i++;
        }
        if(ans > 0) return ans+1;
        return ans;
    }
};






// A 2

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;        
        for(int i=1; i<n-1; i++) {
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int L = i - 1;
                int R = i + 1;
                
                while(L > 0 && arr[L-1] < arr[L]) L--;
                while(R < n-1 && arr[R] > arr[R+1]) R++;
                                
                mx = max(mx, R-L+1);
            }
        }        
        return mx;
    }
};






// A 3




