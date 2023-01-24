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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head;
        while(ptr){
            ListNode* temp = ptr;
            int sum = 0;
            while(temp -> val){
                sum += temp -> val;
                temp = temp -> next;
            }

            ptr -> val = sum;
            ptr -> next = temp -> next; 
            ptr = temp -> next;
        }

        return head -> next;
    }
};


// Approach 2: Iterative
// Time Complexity: O(N)
// Space Complexity: O(1)





