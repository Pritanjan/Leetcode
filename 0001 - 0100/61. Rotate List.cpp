// APPROACH 1

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
            
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }

        k = k % len;   // Adjust k to be within the range of list length
        for(int i=0; i<k; i++){
            fast = fast -> next;
        }

        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = head;
        ListNode* res = slow -> next;
        slow -> next = NULL;

        return res;
    }
};


// Here we are going to use the approach that calculates the length of the list first,
// then get the offset and do the rotation.

// If the input offset is always going to be valid, a fast and slow pointer way is a little better.
// But in the Leetcode version, k could be larger than the length, so we need the length anyway.





// APPROACH 2

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        // Length of the linked list
        int n = 1;
        ListNode* curr = head;
        while (curr->next) {
            n++;
            curr = curr->next;
        }
        // Connect the tail node to the head node to form a cycle
        curr->next = head;
        // Index of the new head node of the rotated linked list
        // Index of the new tail node of the rotated linked list
        for (int i = 0; i < n - k % n - 1; i++) {
            head = head->next;
        }
        ListNode* newHead = head->next;
        // Break the cycle
        head->next = nullptr;
        return newHead;
    }
};


