// APPROACH 1


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



