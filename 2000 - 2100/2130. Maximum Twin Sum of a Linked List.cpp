// A 1

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






