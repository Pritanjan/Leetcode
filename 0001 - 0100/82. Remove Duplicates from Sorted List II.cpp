// \\ APPROPACH 1 [ 2 POINTER INTERATIVE ]

// Use 2 Pointers prev and curr, to traverse the LL while maintaining the distinction b/w
// duplicate and distinct elements.


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr) {
            bool isDuplicate = false;

            while(curr -> next && curr -> val == curr -> next -> val) {
                curr = curr -> next;
                isDuplicate = true;
            }

            if(isDuplicate) prev -> next = curr -> next;
            else prev = curr;
            
            curr = curr -> next;
        }
        return dummy -> next;
    }
};




// \\ APPROACH 2 [ RECURSION ]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        
        if(head -> val == head -> next -> val) {
            while(head -> next && head -> val == head -> next -> val) head = head -> next;
            return deleteDuplicates(head->next);
        } 
        else {
            head -> next = deleteDuplicates(head -> next);
            return head;
        }
    }
};





// \\ APPROACH 3 [ HASH MAP ]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        unordered_map<int, int> cntMap;
        ListNode* curr = head;

        while(curr) {
            cntMap[curr -> val]++;
            curr = curr -> next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        curr = head;
        while(curr) {
            if(cntMap[curr -> val] == 1) {
                tail -> next = curr;
                tail = tail -> next;
            }
            curr = curr -> next;
        }

        tail -> next = nullptr;
        return dummy -> next;
    }
};





// \\ APPROACH 4 [ usingt merge sort ]

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1 -> val < l2 -> val) {
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        } 
        else {
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* secondHalf = slow -> next;
        slow -> next = nullptr;

        ListNode* L = mergeSort(head);
        ListNode* R = mergeSort(secondHalf);

        return merge(L, R);
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;

        // Sort the linked list
        head = mergeSort(head);

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr && curr -> next) {
            if(curr -> val == curr -> next -> val) {
                int duplicateVal = curr -> val;
                while(curr && curr -> val == duplicateVal) {
                    ListNode* temp = curr;
                    curr = curr -> next;
                    delete temp;
                }
                prev -> next = curr;
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};






// \\ APPROACH 5   [ In place ]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)  return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* curr = dummy;

        while(curr -> next && curr -> next -> next) {
            if(curr -> next -> val == curr -> next -> next -> val) {
                int duplicateVal = curr -> next ->val;
                while(curr -> next && curr -> next -> val == duplicateVal) {
                    ListNode* temp = curr -> next;
                    curr -> next = curr -> next -> next;
                    delete temp;
                }
            } 
            else {
                curr = curr -> next;
            }
        }
        return dummy->next;
    }
};

















class Solution {
public:
    ListNode* del(ListNode* head, ListNode* prev = NULL){
        if(head == NULL)
            return NULL;
            
        if ((head->next and head->next->val == head->val) or (prev and prev->val == head->val))
            return del(head->next, head);
        else
            head->next = del(head->next, head);
    
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;

        return del(head, NULL);
    }
};









// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

// Remove duplicates from an unsorted linked list

class Solution{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates( Node *head) {
        if(head == NULL or head -> next == nullptr) return head;
        
        unordered_map<int, int> ump; ump[head -> data]++;
        
        Node* temp = head -> next;
        Node* prevtemp = head;
        
        while(temp){
            if(ump[temp -> data] > 0) {
                prevtemp -> next = temp -> next;
            }
            else {
                ump[temp -> data]++;
                prevtemp = prevtemp -> next;
            }
            temp = temp -> next;
        }
        return head;
    }
};




class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    { 
        //using set to store already seen values in list. 
        unordered_set<int> seen; 
      
        //using two pointers one of which stores first node other null.
        struct Node *curr = head; 
        struct Node *prev = NULL; 
        
        //traversing over the linked list.
        while (curr != NULL) 
        { 
            //if data at current node is already present in set, we skip the 
            //current node and store the node next to current in link of prev. 
            if (seen.find(curr->data) != seen.end()) 
            { 
               prev->next = curr->next;
               //deleting current node which contains duplicates. 
               delete (curr);             
            }
            
            //else we just insert the data at current node in set and update 
            //prev to the current node.
            else
            { 
               seen.insert(curr->data);
               prev = curr; 
            }
            //updating current to the next node of prev node.
            curr = prev->next; 
        } 
        return head;
    }
    
};
