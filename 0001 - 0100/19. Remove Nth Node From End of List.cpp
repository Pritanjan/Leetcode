// A 1 [ fast & slow pointer ]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*fast = head;
        ListNode*slow = head;
        // iterate first n node using fast pointer
        while(n--) fast = fast->next;
        
        // if fast is already null, then we will have to delete head itself. 
	// Therefore return next of head 
        if(!fast) return head -> next;
        
        // Now, iterate till fast reaches the last node of list 
	// while maintaining the gap of n b/w fast and slow.
        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        // remove the nth node from last
        slow -> next = slow -> next -> next;
        return head;
    }
};






// A 2

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur -> next = cur -> next -> next;
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};






// A 3 [ RECURSION ]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }

        if (count == n) {
            ListNode* to_remove = head;
            head = head->next;
            delete to_remove;
            return head;
        }
        head->next = removeNthFromEnd(head->next, n);
        return head;
    }
};


// OR


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = removeNode(head, n);
        return m == n ? head -> next : head;
    }
    
    int removeNode(ListNode* node, int n) {
        if(node -> next == NULL) return 1;
        int m = removeNode(node->next, n);
        if(m == n) {
            if(m == 1) node -> next = NULL;
            else node -> next = node -> next -> next;
        }
        return m+1;
    }
};


// OR


class Solution {
public:
    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head) return NULL;
       head -> next = removeNthFromEnd(head -> next, n);
       cur++;
       if(n == cur) return head -> next;
       return head;
    }
};






// A 4 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        ListNode* h = head;
        ListNode* prev = nullptr;
        ListNode* remove = h;
        while(head != nullptr) {
            if(i-n > 0) {
                prev = remove;
                remove = remove->next;
            }
            head = head->next;
            i++;
        }
        if(prev != nullptr) prev->next = remove->next;
        else h = h->next;
        return h;
    }
};






// A 5 Using Hash Map

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        unordered_map<int, ListNode*> m;
        int index = 1;
        while (temp != nullptr) {
            m[index++] = temp;
            temp = temp->next;
        }
        int size = m.size();
        if (size == 1) {
            return nullptr;
        }
        if (n == 1) {
            m[size-1]->next = nullptr;
        } else if (n == size) {
            head = head->next;
        } else {
            m[size-n]->next = m[size-n+2];
        }
        return head;
    }
};






// A 6 - Using a vector to store nodes

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* curr = head;
        while(curr) {
            v.push_back(curr);
            curr = curr -> next;
        }

        int target = v.size() - n;
        if(target == 0) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        ListNode* prev = v[target - 1];
        ListNode* temp = prev -> next;
        prev -> next = prev -> next -> next;
        delete temp;
        return head;
    }
};






// A 7  -  Using Stack

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> nodes;
        ListNode* curr = head;
        while(curr) {
            nodes.push(curr);
            curr = curr -> next;
        }

        for(int i=0; i<n; i++) nodes.pop();        
        if(nodes.empty()) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        ListNode* prev = nodes.top();
        ListNode* temp = prev -> next;
        prev -> next = prev -> next -> next;
        delete temp;
        return head;
    }
};






