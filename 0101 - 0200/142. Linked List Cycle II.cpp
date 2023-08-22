// APPROACH 1 [ Using Hash Map ]

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map <ListNode*, int> ump;
        ListNode* temp = head;
        while(temp != NULL){
            if(ump.find(temp) != ump.end()) return temp;
            ump[temp]++;
            temp = temp -> next;
        }
        return NULL;
    }
};


// OR 


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        unordered_map<ListNode*, ListNode*> visited;
        while(head) {
            if(visited.count(head)) return visited[head];
            visited[head] = head;
            head = head->next;
        }
        return nullptr;
    }
};





// APPROACH 2

ListNode* detectCycle(ListNode* head) {
    if(!head || !head->next) return NULL;
    unordered_set<ListNode*> ust;
    while(head) {
        if(ust.find(head) != ust.end()) return head;
        else {
            s.insert(head);
            head = head->next;
        }
    }
    return NULL;
}


// OR


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        set<ListNode*>s;
        ListNode* itr = head;
        s.insert(itr);
        while(itr != NULL){
            if(s.find(itr -> next) == s.end()) s.insert(itr -> next);
            else return itr -> next;
            itr = itr -> next;
        }
        return NULL;
    }
};






// APPROACH 3

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head -> next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) { 
                slow = head;
                while(fast != slow) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


// OR 


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)break;
        }

        if (!fast || !fast->next) return nullptr;
        fast = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};


