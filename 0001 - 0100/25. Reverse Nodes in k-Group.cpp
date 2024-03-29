// APPROACH 1 [ Recursive ]

// 1) The first step is to check whether the Head is NULL or Not, if its NULL then
//    we can directly return NULL,
// 2) If the Head is not NULL, then we need to check the length of Linked List starting 
//    from current Head.
// 3) If it is not a multiple of K(Less than K) , then there is no need to reverse it and 
//    hence we can directly return head,
// 4) Else if its a multiple of K, then we have to reverse the K elements starting from current 
//    Head,
// 5) We will follow the same steps for the rest of the elements Recursively.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == NULL) return NULL;
        
        // to stop from reversing in case of some rem element
        //  Eg. --> 1,2,3,4,5 
        ListNode* times = head;
        for(int i=0; i<k; i++) {
            if(times == NULL) return head;
            else times = times -> next;
        }
        
        // S1 -> reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = 0;           
        
        while(curr != NULL and cnt < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }      
        // S2 -> Recursion call
        if(head != NULL) head -> next = reverseKGroup(next, k);        
        return prev;
    }
};

// T.C. --> O(N)


// OR


// use recursion to reverse the nodes in groups of k. It works by reversing the first k nodes,
// then recursively calling the function on the remaining portion of the list.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        // Count the number of nodes in the current group
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            // Reverse the first k nodes
            curr = reverseKGroup(curr, k); // Recurse on the remaining list
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            head = curr; // New head for this group
        }
        
        return head;
        
    }
};

// T.C. --> O(N)



// APPROACH 2 [ Using Iteration ]

// It iterates through the LL while reversing groups of k nodes. 
// It uses a temporary pointer to reverse the nodes within each group.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        // Count the number of nodes
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            curr = head;
            ListNode* prev = nullptr;
            while (count > 0) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                count--;
            }
            if(curr != nullptr) {
                head->next = reverseKGroup(curr, k); // Recurse on the remaining list
            }
            return prev; // New head for this group
        }
        
        return head;
    }
};

// T.C. --> O(N)






// A 3 Iterative Approach with Stack:
// Traverse the linked list in groups of k nodes.
// Use a stack to reverse each group of k nodes.
// Attach the reversed groups back together to form the modified list.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> stk;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(true) {
            int cnt = 0;
            ListNode* tmp = head;
            
            while(tmp && cnt < k) {
                stk.push(tmp);
                tmp = tmp -> next;
                cnt++;
            }
            if(cnt != k) {
                curr -> next = head;
                break;
            }
            
            while(!stk.empty()) {
                curr -> next = stk.top();
                curr = curr -> next;
                stk.pop();
            }
            curr -> next = tmp;
            head = tmp;
        }        
        return dummy -> next;
    }
};





// A 4 - Using Two-Pointer Approach:
// Maintain 2 pointers, one pointing to the start of the current group, 
// and the other pointing to the end of the previous group.
// Reverse each group in-place and connect it to the previous group.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prevGpEnd = dummy;
        ListNode* currGpStrt = head;

        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            len++;
            tmp = tmp -> next;
        }

        while(len >= k) {
            ListNode* curr = currGpStrt;
            ListNode* prev = prevGpEnd;
            for(int i=0; i<k; ++i) {
                ListNode* next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
            prevGpEnd  -> next = prev;
            currGpStrt -> next = curr;
            prevGpEnd = currGpStrt;
            currGpStrt = curr;
            len -= k;
        }
        return dummy -> next;
    }
};






// A 5

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* tail = dummy; // Initialize the tail pointer

        while(true) {
            ListNode* gpStrt = tail -> next;
            ListNode* gpEnd = tail -> next;
            int cnt = 0;
            
            // Check if there are at least k nodes in the group
            while(gpEnd && cnt < k) {
                gpEnd = gpEnd -> next;
                cnt++;
            }
            
            if(cnt == k) { // If there are k nodes in the group
                ListNode* prev = nullptr;
                ListNode* curr = gpStrt;
                // Reverse the k nodes in the group
                for(int i=0; i<k; i++) {
                    ListNode* next = curr -> next;
                    curr -> next = prev;
                    prev = curr;
                    curr = next;
                }
                // Connect the reversed group to the previous tail
                tail -> next = prev;
                gpStrt -> next = curr;
                // Update the tail pointer for the next iteration
                tail = gpStrt;
            } 
            // If there are less than k nodes left, break the loop
            else break;
        }
        return dummy -> next;
    }
};






// A 6

