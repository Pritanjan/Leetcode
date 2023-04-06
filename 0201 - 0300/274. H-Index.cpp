// APPROACH 1

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int L = 0;
        int R = n - 1 ;
        int mid;
        
        while(L <= R){
            mid = L + (R-L)/2;
            if(citations[mid] == (n - mid) )
                return citations[mid];
            else if(citations[mid] > (n - mid))
                R = mid - 1;
            else if(citations[mid] < (n - mid))
                L = mid + 1;
        }
        return n - L;
    }
};





// APPROACH 2


