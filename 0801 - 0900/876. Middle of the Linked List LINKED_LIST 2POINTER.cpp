// APPROACH 1 

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



// Time Complexity: O(N), where N is the number of nodes in the given list.
// Space Complexity: O(N), the space used by A.








// APPROACH 2

// When traversing the list with a pointer first,
// make another pointer second that traverses twice as second. 
// When second reaches the end of the list, first must be in the middle.


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first  = head;
        ListNode* second = head;
        
        while(second != NULL && second->next != NULL){
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};



// Time Complexity: O(N), where NN is the number of nodes in the given list.
// Space Complexity: O(1), the space used by slow and fast.









// APPROACH 3


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
        
        while(middle--){
            temp = temp -> next;
        }
        
        return temp;
    }
};




// OR


// Find the length of the LL then travesrse for n/2

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



