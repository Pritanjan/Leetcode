// APPROACH 1

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
    ListNode *detectCycle(ListNode *head) {
        unordered_map <ListNode*, int> ump;
        ListNode* temp = head;
        
        while(temp != NULL){
            if(ump.find(temp) != ump.end())
                return temp;
            ump[temp]++;
            temp = temp -> next;
        }
        return NULL;
    }
};




// APPROACH 2

class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        set<ListNode*>s;
        ListNode* itr = head;
        s.insert(itr);
        while(itr != NULL){
            if(s.find(itr -> next) == s.end()){
                s.insert(itr -> next);
            }
            else{
                return itr -> next;
            }
            itr = itr -> next;
        }
        return NULL;
    }
};
