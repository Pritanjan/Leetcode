// A 1 [ fast & slow pointer ]
// Use two pointers to create a gap of n nodes between them.
// Move both pointers until the second one reaches the end.
	
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






// A 2 - Two Passes with Counting:
// Traverse the list to count the number of nodes.
// Calculate the position of the node to remove from the start.
// Traverse again to remove the node.

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
// Recursively traverse the list to reach the end.
// Maintain a counter and remove the node when the counter matches n.

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
        unordered_map<int, ListNode*> ump;
        int idx = 1;
        while(temp != nullptr) {
            ump[idx++] = temp;
            temp = temp->next;
        }
        
        int size = ump.size();
        if(size == 1) return nullptr;
        if(n == 1) ump[size - 1] -> next = nullptr;
        else if(n == size) head = head -> next;
        else ump[size - n] -> next = ump[size - n+2];
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






// A 7 - Using Stack
// Push nodes onto a stack while traversing the list.
// Pop n nodes from the stack and update the pointers

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






// A 8 - count nodes & delete nth node

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr) {
            cnt++;
            curr = curr -> next;
        }

        if(cnt == n) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        curr = head;
        for(int i=0; i<cnt-n-1; i++) {
            curr = curr -> next;
        }

        ListNode* temp = curr -> next;
        curr -> next = curr -> next -> next;
        delete temp;
        return head;
    }
};






// A 9 -  Reverse the list, delete the nth node, and reverse again

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        if(n == 1) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return reverseList(head);
        }

        ListNode* curr = head;
        for(int i=0; i<n-2; i++) {
            curr = curr -> next;
        }

        ListNode* temp = curr -> next;
        curr -> next = curr -> next -> next;
        delete temp;
        return reverseList(head);
    }
};






// A 10 - Using a Sliding Window:
// Maintain a window of size n+1 while traversing the list.
// Move the window until the end is reached.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for(int i=0; i<=n; i++) second = second -> next;
        while(second) {
            first = first -> next;
            second = second -> next;
        }
        first -> next = first -> next -> next;

        return dummy -> next;
    }
};






// A 11 
