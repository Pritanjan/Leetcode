// A 1 
// Put every node into an vector v in order. 
// Then the middle node is just v[v.length // 2], 
// since we can retrieve each node by index.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v = {head} ;
        while(v.back()->next != NULL){
            v.push_back(v.back()->next);
        }
        return v[v.size() / 2]    ;
    }
};


// OR


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> res;
        ListNode* curr =  head;
        while(curr != nullptr) {
            res.push_back(curr);
            curr = curr -> next;
        }
        return res[res.size()/2];
    }
};

// Time Complexity: O(N), where N is the number of nodes in the given list.
// Space Complexity: O(N), the space used by A.






// A 2 [ Using slow and fast pointers ]  OR [ Tortoise-Hare-Approach ]
// When traversing the list with a pointer first, make another pointer second that
// traverses twice as second. When second reaches the end of the list, first must be in the middle.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }        
        return slow;
    }
};

// Time Complexity: O(N), where NN is the number of nodes in the given list.
// Space Complexity: O(1), the space used by slow and fast.







// A 3 [ Using two pointers and a counter ]

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = 0; 
        // Traverse temp till the end of linked list to find the length. 
        while(temp){
            temp = temp -> next;
            len++;
        }
        int middle = len/2;
        temp = head;
        while(middle--) temp = temp -> next;        
        return temp;
    }
};


// OR
// [ Finding the length of the LL then travesrse for n/2 ]

class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        ListNode* temp = head;
        int cnt = 0;        
        while(cnt < n/2){
            temp = temp -> next;
            cnt++;
        }
        return temp;
    }
};

// getLength T.C. -- > O(N)
// while execute for n/2 --> O(N/2)
// T.C. --> O(N)






// A 4 [ Using recursion ]

class Solution {
public:
    ListNode* recursion(ListNode* slow, ListNode* fast) {
        if(fast == nullptr || fast->next == nullptr) return slow;
        return recursion(slow->next, fast->next->next);
    }

    ListNode* middleNode(ListNode* head) {        
        return recursion(head, head);
    }
};

// T.C. --> O(N)
// S.C. --> O(N)


// OR


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        int pos = 0;
        recursion(head, mid, pos);return mid;
    }
    void recursion(ListNode* curr, ListNode*& mid, int& pos) {
        if(!curr) return ;        
        recursion(curr -> next, mid, pos);
        if(++pos % 2 == 0) mid = mid -> next;
    }
};


// OR


class Solution {
public:
    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast -> next != tail) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* middleNode(ListNode* head) {
        return findMiddle(head, nullptr);
    }
};






// A 5 [ STACK ]

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* curr = head;
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->next;
        }
        
        int n = stack.size();
        if(n % 2 == 0) n = n / 2;
        else n = (n / 2) + 1;
        
        int cnt = 0;
        ListNode* temp = nullptr;
        while(!stack.empty()) {
            cnt++;
            ListNode* node = stack.top();
            stack.pop();
            if(cnt == n) temp= node;
        }
        return temp;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 6 - Using a Single Pointer and a Counter:
// maintain a counter that keeps track of the number of nodes encountered while traversing the list.
// Then, iterate through the list again to find the middle node using the counter.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* curr = head;
        ListNode* mid = head;
        while(curr != nullptr) {
            if(cnt % 2 == 1) mid = mid -> next;
            cnt++;
            curr = curr -> next;
        }
        return mid;
    }
};





// A 7
