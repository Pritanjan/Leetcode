// Iterative Approach

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Update pointers
            prev = first;
            head = first->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};





// APPROACH 1 
// [ Recursive Approach Using 3 Pointer ]

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {        
        if(!head || !head -> next) return head;
        ListNode* first  = head;
        ListNode* second = head->next;
        ListNode* ptr    = swapPairs(second -> next);
        second -> next = first;
        first  -> next = ptr;
        
        return second;
    }
};




// OR  
// [ Recursive Approach Using 2 Pointer ]


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // Swapping
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};





// APPROACH 2


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL and ptr->next != NULL){
            swap(ptr -> val , ptr->next->val);
                ptr = ptr->next->next;
        }
        return head;
    }
};



// OR


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** pp = &head;

        while (*pp && (*pp)->next) {
            ListNode* first = *pp;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            *pp = second;

            pp = &(first->next);
        }

        return head;
    }
};







// APPROACH 3


class Solution {
public:
    ListNode* vectorToLinkedList(vector<int>& v) {
        if(v.empty()) return nullptr;

        ListNode* head = new ListNode();
        head->val = v[0];
        head->next = nullptr;
        ListNode* current = head;

        for(int i=1; i<v.size(); ++i) {
            ListNode* newNode = new ListNode();
            newNode->val = v[i];
            newNode->next = nullptr;
            current->next = newNode;
            current = newNode;
        }
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        int cnt = 0;

        while(temp != nullptr){
            cnt++;
            v.push_back(temp->val);
            temp = temp -> next;
        }
        
        for(int i=0; i<cnt-1; i+=2){
            swap(v[i], v[i+1]);
        }

        vector<int> p = v;
        ListNode* res = vectorToLinkedList(p);
        return res;
    }
};



