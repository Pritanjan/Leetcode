//https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
//        	while(head != NULL){
            while(head){
                nextNode = head->next;
                head->next = prevNode;
                prevNode = head;
                head = nextNode;
            }
        return prevNode;
    }
};

//we are going to use 3 variables: prevNode, head and nextNode, that you can easily guess what are meant to represent as we go;
//we will initialise prevNode to NULL, while nextNode can stay empty;
//we are then going to loop until our current main iterator (head) is truthy (ie: not NULL), which would imply we reached the end of the list;
//during the iteration, we first of all update nextNode so that it acquires its namesake value, the one of the next node indeed: head->next;
//we then proceeding "reversing" head->next and assigning it the value of prevNode, while prevNode will become take the current value of head;
//finally, we update head with the value we stored in nextNode and go on with the loop until we can. After the loop, we return prevNode.
//I know it is complex, but I find this gif from another platform to make the whole logic much easier to understand (bear in mind we do not need curr and will just use head in its place):



// Iterative solution 
// pg 9

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return head; 
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        
        while(curr != NULL){
            ListNode * fd = NULL;
            fd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fd;
        }
        return prev;
    }
};

// T.C. O(N)
// S.C. O(1)



