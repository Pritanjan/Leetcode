// APPROACH 1 [ fast & slow pointer ]


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*fast = head;
        ListNode*slow = head;
        
        // iterate first n node using fast pointer
        while(n--) fast = fast->next;
        
        // if fast is already null, then we 
        // will have to delete head itself. 
		// Therefore return next of head
        if(!fast) return head -> next;
        
        // Now, iterate till fast reaches the last node of list
	// while maintaining the gap of n b/w fast and slow.
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        
        // remove the nth node from last
        slow -> next = slow -> next -> next;
		
        return head;
    }
};









// APPROACH 2

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur -> next = cur -> next -> next;
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};









// APPROACH 3 [ RECURSION ]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }

        if (count == n) {
            ListNode* to_remove = head;
            head = head->next;
            delete to_remove;
            return head;
        }

        head->next = removeNthFromEnd(head->next, n);
        return head;
    }
};

