//https://leetcode.com/problems/intersection-of-two-linked-lists/

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

