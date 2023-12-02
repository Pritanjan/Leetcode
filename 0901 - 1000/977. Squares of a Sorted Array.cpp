// APPROACH 1 - Brute Force
 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};





// APPROACH 2

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int R = n-1;
        vector<int> ans(n);
        int i = 0;
        // int i = n-1; // then do i-- instead of i++
        
        while(L <= R){
            if(abs(nums[L]) < abs(nums[R])){
                ans[i++] = nums[R] * nums[R];
                R--;
            }
            else{
                ans[i++] = nums[L] * nums[L];
                L++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};






// APPROACH 3 - Optimized Sorting
// It uses transform function to apply the square operation to each element of the input vector A.
// The sort function is then used to sort the resulting vector in non-descending order.
// Now, sorted vector is returned.

// Lambda function used in transform to square each element of the input vector 
// is defined using the [] notation.

class Solution {
public:            
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> B(A.size());
        transform(A.begin(), A.end(), B.begin(), [](int i) { return i * i; });
        sort(B.begin(), B.end());
        return B;
    }
};






// APPROACH 4 [ Direct insertion sorting ] 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> result(n);
        int j;
        for(int i = 0; i < n; i++){
            A[i] = A[i] * A[i];
        }
        for(int i = 1; i < n; i++){
            int temp = A[i];
            for(j=i- 1; j>=0; j--){
                if(temp < A[j]) A[j + 1] = A[j];
                else break;
            }
            A[j + 1] = temp;
        }
        return A;
    }
};






// APPROACH 5

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums) {
            pq.push(num * num);
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};












// APPROACH 1
// APPROACH 1
// APPROACH 1
// APPROACH 1

















