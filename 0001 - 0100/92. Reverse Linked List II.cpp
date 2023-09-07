// A 1
// Find the addresses of the nodes at the left and right position by traversing the given list.
// Reverse the list from left to right separately.
// After the reversal, reattach the list in the original list at the same position.

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        // while(head != NULL){
        while(head){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    ListNode* reverseBetween(ListNode* head, int L, int R) {
        ListNode* CN = head;   // current node
        ListNode* SN;          // strt node
        ListNode* LN;          // last node
        int idx = 1;           // index

        while(CN != NULL){
            if(idx > R) break;
            if(idx < L) SN = CN;
            if(idx == R) LN = CN;

            CN = CN -> next;
            idx++;
        }

        LN -> next = NULL;
        if(L == 1){
            LN = head;
            head = reverse(head);
        }
        else{
            LN = SN -> next;
            SN -> next = reverse(SN -> next);
        }
        LN -> next = CN;
        return head;
    }
};

// 1. It initializes CN (current node), SN (start node), and LN (end node) to head, NULL, and NULL, 
//    and idx to 1.
// 2. It iterates through the list using a while loop until it reaches the Rth node or the end of the list. 
// 3. If idx is less than L, it updates SN to point to the current node (CN) as 
//    it represents the node just before the left position.
// 4. If idx is equal to R, it updates LN to point to the current node (CN) as 
//    it represents the node at the right position.
// 5. It then updates CN and increments idx.
// 6. After the loop, it sets the next pointer of the LN node to NULL, 
//    effectively splitting the list into two parts: the one to be reversed and the rest.
// 7. If L is 1, it means that the reversal starts from the beginning of the list, 
//    so it reverses the entire list using the reverse function and updates the head of the list.
// 8. If L is greater than 1, it means the reversal starts from a node other than the head. 
//    In this case, it reverses the sublist between SN and LN using the reverse function
//    and updates SN->next to point to the new head of the reversed sublist.
// 9. Finally, it connects the reversed sublist (LN->next) to the remaining part of the list (CN)
//    and returns the updated head of the list.

// Time Complexity: O(n)
// Auxiliary Space Complexity: O(1)






// A 2 - Iterative Approach

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(!head or L == R) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        for(int i=1; i<L; i++){
            prev = prev -> next;
        }

        ListNode *curr = prev -> next;
        for(int i=L; i<R; i++) {
            ListNode *tmp = curr -> next;
            curr -> next = tmp -> next;
            tmp -> next = prev -> next;
            prev -> next = tmp;
        }
        return dummy -> next;
    }
};






// A 3 - Recursion

class Solution {
public:        
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(!head || L == R) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        
        // Find the node before the left position
        for(int i=1; i<L; ++i) {
            prev = prev -> next;
        }

        // Reverse the sublist from left to right using recursion
        ListNode* newHead = reverseList(prev -> next, R-L+1);

        // Connect the reversed sublist back to the original list
        prev -> next = newHead;
        return dummy -> next;
    }

    ListNode* reverseList(ListNode* head, int n) {
        if(!head || n <= 1) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(n > 0) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            n--;
        }
        head -> next = current;
        return prev;
    }
};






// A 4 - Using Stack

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(!head || L == R) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        
        // Find the node before the left position
        for(int i=1; i<L; ++i) {
            prev = prev -> next;
        }

        // Use a stack to reverse the sublist from left to right
        stack<ListNode*> stk;
        ListNode* curr = prev -> next;
        for(int i=L; i<=R; ++i) {
            stk.push(curr);
            curr = curr -> next;
        }

        while(!stk.empty()) {
            prev -> next = stk.top();
            stk.pop();
            prev = prev -> next;
        }
        prev -> next = curr;
        return dummy -> next;
    }
};






// A 5 - Use 2 Pointer
// Use 2 pointer to reverse list from left to right

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(!head || L == R) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;

        // Find the node before the left position
        for(int i=1; i<L; ++i) {
            prev = prev -> next;
        }

        // Initialize two pointers for reversal
        ListNode* Lptr = prev -> next;
        ListNode* Rptr = Lptr -> next;

        // Reverse the sublist from left to right
        for(int i=L; i<R; ++i) {
            Lptr -> next = Rptr -> next;
            Rptr -> next = prev -> next;
            prev -> next = Rptr;
            Rptr = Lptr -> next;
        }
        return dummy -> next;
    }
};






// A 6 - 
// Reverses the sublist from left to right separately and then stitches it back into the original list.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(!head || L == R) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;

        // Find the node before the left position
        for(int i=1; i<L; ++i) {
            prev = prev -> next;
        }

        ListNode* curr = prev->next;
        ListNode* rev = nullptr;

        // Reverse the sublist from left to right
        for(int i=L; i<=R; ++i) {
            ListNode* temp = curr -> next;
            curr -> next = rev;
            rev = curr;
            curr = temp;
        }

        // Connect the reversed sublist back to the original list
        prev -> next -> next = curr;
        prev -> next = rev;
                
        return dummy -> next;
    }
};






// A 7 
