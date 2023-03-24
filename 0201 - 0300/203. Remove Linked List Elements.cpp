// APPROACH 1


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;

        while(head && head -> val == val) head = head->next;

        ListNode *p = head;
        ListNode *q;
        
        while(p != nullptr){
            if(p -> val != val){
                q = p;
                p = p -> next;
            }
            else{  
                q -> next = p -> next;
                p = p -> next;
            }
        }
        return head;
    }
};




// APPROACH 2


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head -> val == val) return removeElements(head -> next, val);

        ListNode* temp = head;
        while(temp && temp -> next){
            if(temp -> next -> val == val) temp -> next = temp -> next -> next;
            else temp = temp -> next;
        }

        return head;
    }
};





// APPROACH 3


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        head -> next = removeElements(head -> next, val);
        return head -> val == val ? head -> next : head;
    }
};





