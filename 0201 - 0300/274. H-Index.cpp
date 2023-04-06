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

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end()); // Sort the citations in ascending order
        int n = citations.size();
        int h = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] > h) {
                h++; // Increment h if the citation count is greater than h
            } else {
                break; // Exit the loop if the citation count is less than or equal to h
            }
        }
        return h;
    }
};





class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h;
        priority_queue<int> pq(begin(citations), end(citations));
        
        for (h = 0; !pq.empty() && h < pq.top(); ++h)
            pq.pop();  

        return h;
    }
};

