// A 1 - Using a Temporary Array

// It creates a temporary array to store the rotated elements efficiently. 
// It calculates the new index for each element in the temporary array and
// then copies the elements back to the original array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n);
        int i = 0;
        k %= n;
        
        for(int j=n-k; j<n; j++) ans[i++] = nums[j];
        for(int j=0; j<n-k; j++) ans[i++] = nums[j];        
        nums = ans;
    }
};


// OR


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        vector<int> temp(n);        
        for(int i=0; i<n; i++) {
            temp[(i + k) % n] = nums[i];
        }        
        nums = temp;
    }
};






// A 2
// STL
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
                                                          // {1, 2, 3, 4, 5, 6, 7}
                               							  // k = 3
        reverse(nums.begin(),nums.end());		          // {7, 6, 5, 4, 3, 2, 1}
        reverse(nums.begin(),nums.begin()+k);		      // {5, 6, 7, 4, 3, 2, 1}
        reverse(nums.begin()+k,nums.end());			      // {5, 6, 7, 1, 2, 3, 4}
    }
};


// 
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    public static void reverse(int[] a, int start, int end) {
        while (start < end) {
            int tmp = a[start];
            a[start] = a[end];
            a[end] = tmp;
            start++;
            end--;
        }
    }
}








// A 3

class Solution {
public:        
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        int L = 0;
        int R = n - 1;
        while(L < R) swap(nums[L++], nums[R--]);
        
        L = 0;
        R = k - 1;
        while(L < R) swap(nums[L++], nums[R--]);

        L = k;
        R = n - 1;
        while(L < R) swap(nums[L++], nums[R--]);
    }
};






// A 4

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return; // No rotation needed
        
        int cnt = 0;
        for(int i=0; cnt<n; i++) {
            int curr = i;
            int prev = nums[i];
            do {
                int next = (curr + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                cnt++;
            } while (i != curr);
        }
    }
};






// A 5  Using a Deque (Double-Ended Queue)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        if(k == 0) return; // No rotation needed
        
        deque<int> dq(nums.begin(), nums.end());
        for(int i=0; i<k; i++) {
            int val = dq.back();
            dq.pop_back();
            dq.push_front(val);
        }        
        nums.assign(dq.begin(), dq.end());
    }
};






// A 6 - Using a Temporary Queue
// Same as A 1 insteaad of vector awe are using queue

// It uses a queue to temporarily store the last 'k' elements and 
// then shifts the first 'n-k' elements to the right and
// copies the elements from the queue back to the beginning

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> temp;
        k %= n;
                
        for(int i=n-k; i<n; i++) temp.push(nums[i]);        
        for(int i=n-k-1; i>=0; i--) nums[i+k] = nums[i];        
        for(int i=0; i<k; i++) {
            nums[i] = temp.front();
            temp.pop();
        }
    }
};






// A 7 -  Using a Set to Handle Cyclic Permutations

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        // if (k == 0) return; // No rotation needed

        set<int> visited;
        for(int i=0; visited.size()<n; i++) {
            int curr = i;
            int prev = nums[i];
            do {
                int next = (curr + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                visited.insert(curr);
            } while(i != curr);
        }
    }
};






// A 8
