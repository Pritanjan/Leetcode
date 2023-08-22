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





// APPROACH 3 [  Using Vector to Store Values ]

// Here, we can convert the LL values into a vector, perform the rotation on the vector, 
// and then reconstruct the linked list with the rotated values.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;        
        vector<int> v;
        ListNode* curr = head;
        while(curr) {
            v.push_back(curr -> val);
            curr = curr -> next;
        }
        
        int length = v.size();
        k = k % length;
        
        rotate(v.rbegin(), v.rbegin() + k, v.rend());
        
        curr = head;
        for(int i=0; i<length; i++) {
            curr -> val = v[i];
            curr = curr -> next;
        }        
        return head;
    }
};





// APPROACH 4 [ RECURSION ]

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while(head) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
                
        int length = getLength(head);
        k = k % length;
        
        // No rotation needed
        if(k == 0) return head;  
        
        ListNode* curr = head;
        for(int i=0; i<length-k-1; i++) {
            curr = curr -> next;
        }
        
        ListNode* new_head = curr -> next;
        curr -> next = nullptr;
        
        new_head = rotateRight(new_head, k);
        
        ListNode* new_tail = new_head;
        while(new_tail -> next) new_tail = new_tail -> next;
        new_tail -> next = head;
        return new_head;
    }
};



