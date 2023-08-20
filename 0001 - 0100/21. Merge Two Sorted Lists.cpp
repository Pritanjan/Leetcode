// APPROACH 1 [ RECURISON ]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If the list 1 is empty then return list 2
        if(list1 == NULL) return list2;
        // If the list 2 is empty then return list 1
        if(list2 == NULL) return list1;
        
        // if value pointed by list1 pointer is <= to value pointed by list2 pointer
        if(list1->val <=list2->val){
            list1->next = mergeTwoLists(list1->next, list2); return list1;
        }
        
        // we will call recursive l1 whole list and l2 -> next
        else {
            list2->next = mergeTwoLists(list2->next, list1); return list2;
        }
        return 0;    
    }
};





// APPROACH 2

class Solution {
public:
    ListNode* solve(ListNode* first, ListNode* second) {
        // if one element is present in the first
        if(first -> next == NULL){
            first -> next = second;
            return first;
        }
    
        ListNode* curr1 = first; 
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2 -> next;
    
        while(next1 != NULL and curr2 != NULL){
            if((curr2 -> val >= curr1 -> val) and (curr2 -> val <= next1 -> val)) {
                // adding node in b/w the first list
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1; 
            
                // update pointer
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1 = next1;
                next1 = next1 -> next;
            
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
                }
            }   
        }
        return first;
    }
    
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first == NULL)  return second;
        if(second == NULL) return first;
        if(first -> val <= second -> val) return solve(first, second);
        else return solve(second, first);
    }    
};






// APPROACH 3

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1), *p = dummy;
        ListNode* p1 = list1, *p2 = list2;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            }
            else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }        
        if (p1 != NULL) p->next = p1;
        if (p2 != NULL) p->next = p2;
        return dummy->next;
    }
};






// APPROACH 4 IATERATIVE APPROACJHH

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(list1 && list2) {
            if(list1 -> val < list2 -> val) {
                curr -> next = list1;
                list1 = list1 -> next;
            } 
            else {
                curr -> next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
        }
        curr -> next = list1 ? list1 : list2;
        return dummy.next;
    }
};






// APPROACH 5 [ Using Extra Space (Additional Memory) ]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(list1 && list2) {
            if(list1 -> val < list2 -> val) {
                curr -> next = new ListNode(list1 -> val);
                list1 = list1 -> next;
            } 
            else {
                curr -> next = new ListNode(list2 -> val);
                list2 = list2 -> next;
            }
            curr = curr -> next;
        }

        while(list1) {
            curr -> next = new ListNode(list1 -> val);
            list1 = list1 -> next;
            curr = curr -> next;
        }

        while(list2) {
            curr -> next = new ListNode(list2 -> val);
            list2 = list2 -> next;
            curr = curr -> next;
        }
        return dummy.next;
    }
};





// APPROACH 6 [  Iterative Approach with Optimized Memory ]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(list1 && list2) {
            ListNode*& next = (list1 -> val < list2 -> val) ? list1 : list2;
            curr -> next = next;
            next = next -> next;
            curr = curr -> next;
        }
        curr -> next = list1 ? list1 : list2;
        return dummy.next;
    }
};





// APPROACH 7 [ Using Priority Queue (Min Heap) ]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct Compare {
            bool operator()(const ListNode* a, const ListNode* b) {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        while(list1) {
            pq.push(list1);
            list1 = list1 -> next;
        }

        while(list2) {
            pq.push(list2);
            list2 = list2 -> next;
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!pq.empty()) {
            curr -> next = pq.top();
            pq.pop();
            curr = curr -> next;
        }
        return dummy.next;
    }
};




