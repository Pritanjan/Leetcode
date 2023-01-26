SAME AS LC Q 445 Add Two Numbers II

// APPROACH 1

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* temp = new ListNode(0) ;
        
        ListNode* ans = temp;
        
        
        // ListNode* rtn = new ListNode((l1->val + l2->val) % 10);
        
        while(l1 or l2){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            
            if(sum > 9)
                sum = 1;
            else 
                sum = 0;
        }
        
        if(sum)
            temp -> next = new ListNode(sum);
        
        return ans -> next;
    }
};


// Time complexity :  O(max(m,n)). Assume that mm and nn represents the length of L1 and L2 respectively, the algorithm above iterates at most max(m,n) times.

// Space complexity : O(max(m,n)). The length of the new list is at most max(m,n)+1.

    
// APPROACH 2
class Solution {
public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* &head){
        Node* curr=head;
        Node* prev=NULL;
        Node* nex;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        int carry=0;
        int sum=0;
        Node* temp;
        Node* res=NULL;
        Node* curr=NULL;
        while(first!=NULL or second!=NULL){
            sum=carry+(first?first->data:0)+(second?second->data:0);
            carry=(sum>=10)?1:0;
            sum=sum%10;
            temp=new Node(sum);
            if(res==NULL)
            res=temp;
            
            else
                curr->next=temp;
                curr=temp;
            if(first)
            first=first->next;
            if(second)
            second=second->next;
        }
        if(carry>0){
            temp=new Node(carry);
            curr->next=temp;
            curr=temp;
        }
        res=reverse(res);
        return res;
    }
};



// APPROACH 3


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    struct Node* reverse(struct Node* l1){
        struct Node* p = l1, *q = NULL, *r = NULL;    
        while(p!=NULL){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }

    struct Node* addTwoLists(struct Node* l11, struct Node* l22) {
        struct Node*l1 = reverse(l11);
        struct Node*l2 = reverse(l22);
        struct Node* l3 = new Node(-1);
        struct Node* curr = l3;       
        int carry = 0;
        
        while(l1 || l2 || carry){
            if(l1!=NULL){
                carry += l1->data;
                l1 = l1->next;
            }

            if(l2!=NULL){
                carry += l2->data;
                l2 = l2->next;
            }

            curr->next = new Node(carry%10);
            carry /= 10;
            curr = curr->next;        
        }
        
        struct Node* l33 = reverse(l3->next);

        return l33;
    }
};


// aPRROaCH 4

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};



