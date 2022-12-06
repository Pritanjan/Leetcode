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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* odd  = head;
        ListNode* even = head -> next;
        ListNode* evenhead = head -> next;
        
        // `even != null` rules out the list of only 1 node
        // `even.next != null` rules out the list of only 2 nodes
        while(even != NULL and even -> next != NULL){
            // put odd to the odd list
            odd ->next = odd -> next -> next;
            // Move the pointer to the next odd
            odd = odd -> next;
        
            // put even to the even list
            even -> next = even -> next -> next;
            // Move the pointer to the next even
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;    
    }
};




2-pointer
The idea is to maintain two pointers, one of which stores the list of nodes at odd positions and the other stores the list of nodes at an even position and then finally merge them.

 

The steps are as follows:

Maintain a pointer ‘res’ which stores the final head, which we will return as the final result, also a pointer ‘evenHeadBegin’, which points to the beginning of the linked list of even positioned nodes.
Maintain a pointer ‘oddHead’, which is used to tag along with the nodes at odd positions, similarly ‘evenHead’, which is used to tag along with nodes at even positions.
Loop till ‘evenHead’ and next of ‘evenHead’ is not NULL:
The ‘next’ pointer of ‘oddHead’should point to ‘next’ of ‘evenHead’
Move the ‘oddHead’ pointer ahead.
Similarly, now the ‘next’ pointer of ‘evenHead’ should point to the ‘next’ pointer of 'oddHead'.
And then move the ‘evenHead’ pointer ahead.
After exiting the loop, ‘oddHead’ next should point to ‘evenHeadBegin’ so that both linked lists are concatenated.
Return ‘res’ as the final head of the newly formed linked list.
Time Complexity
O(N), where ‘N’ is the size of the linked list.

 

We are just doing a linear traversal of the linked list. Hence, the final time complexity will be O(N). 

Space Complexity
O(1).

 

Since we are not using any extra space, the overall space complexity is O(1).

