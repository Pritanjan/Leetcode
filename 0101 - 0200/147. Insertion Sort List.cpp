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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* res = new ListNode();

        while(curr){
            ListNode* prev = res;
            while(prev -> next != NULL && prev -> next -> val <= curr -> val){
                prev = prev -> next;
            }

            ListNode* next = curr -> next;
            curr -> next = prev -> next;
            prev -> next = curr;

            curr = next;
        }
        return res -> next;
    }
};

// N be the number of elements in the input list.
// Time Complexity: O(N^2)
// First of all, we run an iteration over the input list.
// At each iteration, we insert an element into the resulting list. In the worst case where the
// position to insert is the tail of the list, we have to walk through the entire resulting list.
// As a result, the total steps that we need to walk in the worst case would be N(N+1)/2  .

// To sum up, the overall time complexity of the algorithm is O(N^2).


// Space Complexity: O(1)
// We used some pointers within the algorithm. However, their memory consumption is constant 
// regardless of the input.
// Note, we did not create new nodes to hold the values of input list, but simply reorder the 
// existing nodes.



