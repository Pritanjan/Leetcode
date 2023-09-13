// A 0 BRUTE FORCE

class Solution {
public:
    void insertNode(ListNode* &head, int val) {
        ListNode* tmp = new ListNode(val);
        if(head == NULL) {
            head = tmp;
            return;
        }

        ListNode* temp = head;
        while(temp -> next != NULL) temp = temp->next;
        temp -> next = tmp;
        return;
    }

    void createCycle(ListNode* &head, int pos) {
        ListNode* ptr = head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp -> next != NULL) {
            if(cnt != pos) {
                ++cnt;
                ptr = ptr -> next;
            }
            temp = temp -> next;
        }
        temp -> next = ptr;
    }

    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> st;
        while(head != NULL) {
            if(st.find(head) != st.end()) return head;
            st.insert(head);
            head = head -> next;
        }
        return NULL;
    }
};

// T.C. : O(N) Iterating the entire list once.
// S.C. : O(N) We store all nodes in a hash table.





// A 1 [ Using Hash Map ]

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





// A 2

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






// A 3

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





// A 4 -  Floyd's Tortoise and Hare Algorithm (Without Extra Data Structures)
// It uses two pointers, slow and fast, to traverse the list. 
// Once a cycle is detected, it finds the starting node of the cycle as in the previous approaches.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect if there is a cycle
        bool hasCycle = false;
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            // If there is a cycle, break the loop
            if(slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If there is no cycle
        if(!hasCycle) return nullptr;
        
        // Phase 2: Find the starting node of the cycle
        slow = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow; // Return the starting node of the cycle
    }
};






// A 5

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = nullptr;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                meet = slow;
                break;
            }
        }

        if(meet == nullptr) return nullptr; // No cycle
        
        slow = head;
        while(slow != meet) {
            slow = slow -> next;
            meet = meet -> next;
        }
        return slow; // Return the starting node of the cycle
    }
};





// A 6 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = nullptr;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                meet = slow;
                break;
            }
        }

        if(meet == nullptr) return nullptr; // No cycle
        
        slow = head;
        while(slow != meet) {
            slow = slow -> next;
            meet = meet -> next;
        }
        return slow; // Return the starting node of the cycle
    }
};





