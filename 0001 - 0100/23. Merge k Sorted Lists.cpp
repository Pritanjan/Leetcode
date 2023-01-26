// Approach 1: Brute Force
// Intuition & Algorithm

// Traverse all the linked lists and collect the values of the nodes into an array.
// Sort and iterate over this array to get the proper value of nodes.
// Create a new sorted linked list and extend it with the new nodes.


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for (auto l : lists) {
            while (l) {
                nodes.push_back(l -> val);
                l = l -> next;
            }
        }

        sort(nodes.begin(), nodes.end());
        ListNode* head = new ListNode(0);
        ListNode* point = head;

        for (auto x : nodes) {
            point -> next = new ListNode(x);
            point = point -> next;
        }
        
        return head -> next;
    }
};


// Complexity Analysis

// Time complexity : O(N log ⁡N) where N is the total number of nodes.
// Collecting all the values costs O(N)) time.
// A stable sorting algorithm costs O(N log⁡ N) time.
// Iterating for creating the linked list costs O(N) time.

// Space complexity : O(N).
// Sorting cost O(N) space (depends on the algorithm you choose).
// Creating a new linked list costs O(N) space.







