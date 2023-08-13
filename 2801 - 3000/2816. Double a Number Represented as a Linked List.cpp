// APPROACH 1

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* newHead = nullptr;
        curr = nullptr;
        int carry = 0;

        while(prev) {
            int dob = prev->val * 2 + carry;
            carry = dob / 10;

            if(!newHead) {
                newHead = new ListNode(dob % 10);
                curr = newHead;
            } 
            else {
                curr -> next = new ListNode(dob % 10);
                curr = curr-> next;
            }
            prev = prev ->next;
        }

        if(carry > 0) curr -> next = new ListNode(carry);
        
        ListNode* res = nullptr;
        curr = newHead;
        while(curr) {
            ListNode* next = curr -> next;
            curr ->next = res;
            res = curr;
            curr = next;
        }
        return res;
    }
};






// APPROACH 2

class Solution {
public:
    int dfs(ListNode* head) {
        if(head == nullptr) return 0;
        head -> val = head -> val << 1 |dfs(head -> next);
        if(head -> val < 10)return 0;
        else {
            head -> val -= 10;
            return 1;
        }
    }

    ListNode* doubleIt(ListNode* head) {
        if(dfs(head)) head =new ListNode(1, head);
        return head;
    }
};


