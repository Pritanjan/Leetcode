// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode *, bool> ump;
        while(headA != NULL){
            ump[headA] = true;
            headA = headA -> next;
        }
        
        while(headB != NULL && ump.find(headB) == ump.end()){
            headB = headB -> next;
        }
        
        return headB;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        while(temp1 != temp2){
            if(temp1 == NULL)
                temp1 = headB;
            else 
                temp1 = temp1->next;
            
            if(temp2 == NULL)
                temp2 = headA;
            else 
                temp2 = temp2->next;
        }
        return temp1;
    }
};









// https://practice.geeksforgeeks.org/problems/eae1fbd0ac8f213a833d231e26ba4d829e79dd9c/1

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2){
        Node *p = head1, *q = head2;
        while(p != q) {
            p = p->next == NULL ? head2 : p->next,
            q = q->next == NULL ? head1 : q->next;
        }
        return p->data;
    }
};

// Retunr common element




