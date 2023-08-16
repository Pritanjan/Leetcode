// APPROACH 1 Create Two Separate Lists:

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less  = new ListNode(0);
        ListNode* smaller = less;
        ListNode* high = new ListNode(0);
        ListNode* greater = high;

        while(head != NULL){
            if(head -> val < x) {
                smaller -> next = head;
                smaller = smaller -> next;
            }
            else{
                greater -> next = head; 
                greater = greater -> next;
            }
            head = head -> next;
        }
        greater -> next = NULL;
        smaller -> next = high -> next;

        return less -> next; 
    }
};

// Time Complexity: O(N), where NNN is the number of nodes in the original linked list and
// we iterate the original list.

// Space Complexity: O(1), we have not utilized any extra space, the point to note is that
// we are reforming the original list, by moving the original nodes, we have not used any
// extra space as such.






// APPROACH 2 RECURSIO 

class Solution {
public:      
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* smaller = partition(head -> next, x);
        if(head -> val < x) {
            head -> next = smaller;
            return head;
        }
        else {
            ListNode* curr = smaller;
            ListNode* prev = nullptr;
            while(curr != nullptr and curr -> val < x){
                prev = curr;
                curr = curr -> next;
            }
            
            if(prev != nullptr) {
                ListNode* temp = prev -> next;
                prev -> next = head;
                head -> next = temp;
            } 
            else {
                head -> next = smaller;
                return head;
            }          
            return smaller;
        }
    }
};





// APPROACH 3  In-Place Rearrangement:

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* insertPos = dummy;
        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr != nullptr) {
            if(curr -> val < x) {
                if(insertPos != prev) {
                    prev -> next = curr -> next;
                    curr -> next = insertPos -> next;
                    insertPos -> next = curr;
                }
                else prev = curr;

                insertPos = curr;
                curr = prev->next;
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy -> next;
    }
};


