// APPROACH 1 [ USING 2 POINTER ]
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

// we are going to use 3 variables: prevNode, head and nextNode, that can easily guess
// what are meant to represent as we go;

// we will initialise prevNode to NULL, while nextNode can stay empty;
// we are then going to loop until our current main iterator (head) is truthy
// (ie: not NULL), which would imply we reached the end of the list;
// during the iteration, we first of all update nextNode so that it acquires its namesake value,
// the one of the next node indeed: head->next;
// we then proceeding "reversing" head->next and assigning it the value of prevNode,
// while prevNode will become take the current value of head;
// finally, we update head with the value we stored in nextNode and go on with the loop 
// until we can. After the loop, we return prevNode.
// I know it is complex, but I find this gif from another platform to make the whole 
// logic much easier to understand (bear in mind we do not need curr and will just use 
// head in its place):





// A 2 [ USING 3 POINTER ]

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode *p1, *p2, *p3;
        p1 = head; 
        p2 = head ->next;
        p3 = p2 ->  next;
        p1 -> next = NULL;
     
        if(p3 == NULL) {
            p2 -> next = p1;
            head = p2;
        }
        else {
           while(p3 != NULL) {
               p2 -> next = p1;
               p1 = p2;
               p2 = p3;
               p3 = p3 -> next;
           }
           p2 -> next = p1;
           head = p2;
        }
        return head;
    }
};





// A 3 [ Iterative solution ] pg 9

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head -> next == NULL) return head; 
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr != NULL){
            ListNode * fd = NULL;
            fd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fd;
        }
        return prev;
    }
};

// T.C. O(N)
// S.C. O(1)





// A 4 [ Recursion ]

class Solution {
public:
    void Recursion(ListNode* &head, ListNode* curr, ListNode* prev){
        // base case ie we reached at last element
        if(curr == NULL){
            head = prev;
            return ;
        }
        Recursion(head,  curr -> next, curr);          
        // curr -> next = prev;
    }    
    ListNode* reverseList(ListNode* head) {
        ListNode * curr = head;
        ListNode * prev = NULL;
        Recursion(head, curr, prev);
        return head;        
    }
};

// T.C. O(N)
// S.C. O(N)


// OR


class Solution {
public:
    ListNode* Recursion(ListNode* head){
        // base case
        if(head == NULL or head -> next == NULL) return head;
        ListNode* temp = Recursion(head -> next);        
        head -> next -> next = head;
        head -> next = NULL;        
        return temp;
    }
    
    ListNode* reverseList(ListNode* head) {
        return Recursion(head);
            
    }   
};

// T.C. O(N)
// S.C. O(N)





// A 5 [ Using stack ] FIFO
//  because stacks uses FIFO The implementation principle is to put the linked list nodes
// into the stack one by one, and then out of the stack one by one after all the stacks, 
// and when they come out of the stack, they are stringing the nodes of the stack into a 
// new linked list. 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        while(head != NULL){
            s.push(head);
            head = head->next;
        }

        if(s.empty()) return NULL;        
        ListNode* node = s.top();
        s.pop();
        ListNode* dummy = node;
        while(!s.empty()){
            ListNode* temp = s.top();
            s.pop();
            node->next = temp;
            node = node->next;
        }
        node->next = NULL;
        return dummy;
    }
};


// OR


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stk;
        while(head != nullptr) {
            stk.push(head);
            head = head -> next;
        }
        
        ListNode* newHead = nullptr;
        ListNode* curr = nullptr;
        while(!stk.empty()) {
            if(newHead == nullptr) {
                newHead = stk.top();
                curr = newHead;
            } 
            else {
                curr -> next = stk.top();
                curr = curr -> next;
            }
            stk.pop();
        }        
        if(curr != nullptr) curr -> next = nullptr;        
        return newHead;
    }
};






// A 6 [ Reversing in Pairs ]
// We reverse the LL in pairs of nodes. This is useful when we want to reverse the list
// in a grouped manner.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }        
        return reverseKGroup(head, len);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        int cnt = 0;
        while(curr != nullptr && cnt < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next != nullptr) head->next = reverseKGroup(next, k); // Recursive call for next group
        return prev; // New head of the reversed list
    }
};





// A 7  [ Reversing by Swapping Values ]
// Here, we swap values of nodes symmetrically across the middle of the list until we reach middle.
// This method doesn't involve changing pointers but just swaps the values in the nodes.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        int cnt = 0; // Count the number of nodes
        while(curr) {
            cnt++;
            curr = curr -> next;
        }

        int i = 0;
        int j = cnt - 1;
        curr = head;
        while(i < j) {
            ListNode* node_i = getNodeAtPosition(head, i);
            ListNode* node_j = getNodeAtPosition(head, j);
            swap(node_i -> val, node_j -> val);
            i++;
            j--;
        }
        return head;
    }    
private:
    ListNode* getNodeAtPosition(ListNode* head, int pos) {
        ListNode* curr = head;
        for(int i=0; i<pos && curr; ++i) {
            curr = curr -> next;
        }
        return curr;
    }
};





