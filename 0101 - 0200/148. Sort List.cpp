/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL and fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* L, ListNode* R){
        if(L == NULL)
            return R;
        if(R == NULL)
            return L; 
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(L != NULL and R != NULL){
            if(L -> val < R -> val){
                temp -> next = L;
                temp = L;
                L = L -> next;
            }
            else{
                temp -> next = R;
                temp = R;
                R = R -> next;
            }
        }
        
        while(L != NULL){
            temp -> next = L;
            temp = L;
            L = L -> next;    
        }

        while(R != NULL){
            temp -> next = R;
            temp = R;
            R = R -> next;    
        }
        ans = ans -> next;
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return head;
        
        // break LL into 2 halves, after finding mid
        ListNode* mid = findMid(head);
        
        ListNode* L = head;
        ListNode* R = mid -> next;
        mid -> next = NULL;
        
        // recursive calls to sort both halves
        L = sortList(L);
        R = sortList(R);
        
        // merge both L and R halves
        ListNode* ans = merge(L, R);
            
        return ans;
    }
};


// T.C. --> O(N Log N)
// S.C. --> O(Log N)





// Sort linked list of 0s 1s 2s
// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

// Separate each node and reconnect.

Node* sortList(Node *head) {
    int zerocnt = 0;
    int onecnt = 0;
    int twocnt = 0;
    
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)
            zerocnt++;
        else if(temp -> data == 1)
            onecnt++;    
        else if(temp -> data == 2)
            twocnt++;
        
        temp = temp -> next;
    }
    
    temp = head;
    while(temp != NULL){
        if(zerocnt != 0){
            temp -> data = 0;
            zerocnt--;
        }
        else if(onecnt != 0){
            temp -> data = 1;
            onecnt--;
        }
        else if(twocnt != 0){
            temp -> data = 2;
            twocnt--;
        }
        temp = temp -> next;
    }
    return head;
}

// T.C. --> O(n)



// APPROACH 2
// Count the number of occurrences, then update the linked list.

void insertAtTail(Node* &tail, Node* &curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head) {
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    
    //create seperate list 0s, 1s and 2s
    while(curr != NULL){
        int val = curr -> data;
        if(val == 0)
            insertAtTail(zerotail, curr);
        else if(val == 1)
            insertAtTail(onetail, curr);
        else if(val == 2)
            insertAtTail(twotail, curr);
        
        curr = curr -> next;
    }
    
    // merge 3 LL
    
    // 1s is not empty
    if(onehead -> next != NULL)
        zerotail -> next = onehead -> next;
    else
        // 1s is empty 
        zerotail -> next = twohead -> next;
    
    onetail -> next = twohead -> next;
    twotail -> next = NULL;
    
    // setup head
    head = zerohead -> next;

    // delete dummy node
    delete zerohead;
    delete onehead;
    delete twohead;
    
    return head;
}

// T.C. --> O(n)
// S.C. --> O(1)




