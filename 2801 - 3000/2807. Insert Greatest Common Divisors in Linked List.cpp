// A 1

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* curr = head;
        while (curr->next) {
            int val = gcd(curr->val, curr->next->val);
            ListNode* tmp = new ListNode(val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        return head;
    }
};


//  OR

