// A 1 - Use an Array

class Solution {
public:
    int pairSum(ListNode* head) {
        // int i = 0;
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        int n = v.size();
        int mx = 0;
        for(int i=0; i<n/2; i++){
            mx = max(mx, v[i] + v[n-i-1]);
        }
        return mx;
    }
};






// A 2

class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* slow = head;
        ListNode* fast = head;

        // Let slow point to the start of the second half
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        // Tail points to the end with reversed second half
        ListNode* tail = reverse(slow);
        while (tail) {
            ans = max(ans, head->val + tail->val);
            head = head->next;
            tail = tail->next;
        }
        return ans;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// T.C. --> O(N)
// S.C. --> O(1)





// A 3

class Solution {
public:
    int getSize(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            size++;
            curr = curr -> next;
        }
        return size;
    }

    int pairSum(ListNode* head) {
        int n = getSize(head);
        int mid = n / 2;

        stack<int> stk;
        ListNode* curr = head;
        for (int i = 0; i < mid; ++i) {
            stk.push(curr -> val);
            curr = curr -> next;
        }

        int maxSum = INT_MIN;
        for(int i=mid; i<n; ++i) {
            int tmp = stk.top();
            stk.pop();
            int currSum = tmp + curr -> val;
            maxSum = max(maxSum, currSum);
            curr = curr -> next;
        }
        return maxSum;
    }
};

