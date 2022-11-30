// https://practice.geeksforgeeks.org/problems/reorder-list/1

// https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

// APPROACH 1    using stack

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head or !head -> next or !head -> next -> next )
            return ;
        
        stack<ListNode*> st;
        ListNode* temp = head;
        int size = 0;
        
        while(temp != NULL){
            st.push(temp);
            size++;
            temp = temp -> next;
        }
        
        ListNode* ptr = head;
        
        for(int i=0; i<size/2; i++){
            // ListNode* 
            st.top() -> next = ptr -> next;
            ptr -> next = st.top();
            ptr = ptr -> next -> next;
            st.pop();
        }
        ptr -> next = NULL;
        
    }
};





// APPROACH 2   Using deque T.C O(N)   S.C O(N)
 
class Solution {
public:   
    void reorderList(ListNode* head) {
        deque<int>q;
        ListNode*temp = head;
        
        while(temp) {
            q.push_back(temp -> val);
            temp = temp -> next;
        }
        
        temp = head;
        int i = 1;
        while(temp) {
            if(i % 2 == 0) {
                temp -> val=q.back();
                q.pop_back();
            }
            else{
                temp->val = q.front();
                q.pop_front();
            }
            i++;
            temp = temp->next;
        }        
    }
};



// APPROACH 3

// 1. Split the list into 2 halves. Next reverse the second half.
// 2. Now, merge the 2 halves while picking elements alternatively from each half.

class Solution {
public:    
    void reorderList(struct Node* head) {
        int r = 0, c;
        struct Node* temp, *temp1, *temp2, *p;
        temp = head;

        // if list contains 2 or lesser nodes, no change needed
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;

        while (temp != NULL) {
            // finding number of nodes in list
            r++;
            temp = temp->next;
        }

        c = (r + 1) / 2;
        // c represents mid point
        
        temp = head;
        while (c--) {
            p = temp;
            temp = temp->next;
        }

        p->next = NULL;
        // dividing the list into 2
        // temp holds the address to head of second half

        temp1 = NULL;
        temp2 = temp;

        // reversing the second half
        while (temp2 != NULL) {
            p = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = p;
        }
        // second half is now reversed

        p = temp1;
        // merging the 2 halves by selecting nodes alternatively
        Node *a, *b;
        while (p) {
           a = head->next;
           b = p->next;
           
           head->next=p;
           p->next=a;
           
           head=a;
           p=b;
        }
    }
};


// T.C. ->  As we are traversing the list roughly 2N times so the time complexity is O(N),
//          N is length of the string.
// S.C. ->  As we are not using any extra space so the space complexity is O(1).


