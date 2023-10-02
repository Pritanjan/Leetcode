// A 1
// The idea is to maintain two pointers, one of which stores the list of nodes at odd positions 
// and the other stores the list of nodes at an even position and then finally merge them.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* odd  = head;
        ListNode* even = head -> next;
        ListNode* evenhead = head -> next;
        
        // `even != null` rules out the list of only 1 node
        // `even.next != null` rules out the list of only 2 nodes
        while(even != NULL and even -> next != NULL){
            // put odd to the odd list
            odd ->next = odd -> next -> next;
            // Move the pointer to the next odd
            odd = odd -> next;
        
            // put even to the even list
            even -> next = even -> next -> next;
            // Move the pointer to the next even
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;    
    }
};

// T.C. --> O(N) There are total n nodes and we visit each node once.
// S.C. --> O(1). Since we are not using any extra space, the overall space complexity is O(1).


// OR
// Same as above

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* oddHead = head;
        ListNode* evenHead = head -> next;
        ListNode* odd  = oddHead;
        ListNode* even = evenHead;        
        
        while(even != NULL and even -> next != NULL){
            odd ->next = even -> next;
            odd = odd -> next;
        
            even -> next = odd -> next;
            even = even -> next;
        }
        odd -> next = evenHead;
        return oddHead;    
    }
};


// OR


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode oddHead(0);
        ListNode evenHead(0);
        ListNode* odd  = &oddHead;
        ListNode* even = &evenHead;        
        
        for(int isOdd=0; head; head = head -> next) {
            if(isOdd ^= 1) {
                odd -> next = head;
                odd = odd -> next;
            }
            else {
                even -> next = odd -> next;
                even = even -> next;
            }
        }
        odd -> next = evenHead.next;
        even -> next = nullptr;
        return oddHead.next;
    }
};






// A 2
// Traverse the list, creating two separate lists for odd and even nodes.
// Combine the two lists at the end.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {          
        if (!head || !head->next) return head;
        ListNode *oddHead = new ListNode(0), *odd = oddHead;
        ListNode *evenHead = new ListNode(0), *even = evenHead;
        int idx = 1;
        while(head) {
            if(idx % 2 == 1) {
                odd -> next = head;
                odd = odd -> next;
            } 
            else {
                even -> next = head;
                even = even -> next;
            }
            head = head -> next;
            idx++;
        }
        odd -> next = evenHead -> next;
        even -> next = nullptr;
        return oddHead->next;
    }
};


