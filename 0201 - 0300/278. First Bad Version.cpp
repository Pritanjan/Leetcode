// APPROACH 1

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1;
        int R = n;
        int ans = -1;
        
        while(L <= R){
            int mid = L + (R-L)/2;
            
            if(isBadVersion(mid)){
                // return mid;
                ans = mid;
                R = mid - 1;
            }
            else L = mid + 1;            
        }
        // return -1;
        return ans;
    }
};





// OR



class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while(L <= R) {
            int mid = L + (R - L) / 2;
            if(isBadVersion(mid)) R = mid - 1;
            else L = mid + 1;
        }
        return L;
    }
};



