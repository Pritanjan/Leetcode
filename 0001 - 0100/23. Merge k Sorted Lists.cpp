// APPROACH 1 : Brute Force

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





// APPROACH 2

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto list : lists) {
            if (list) pq.push({list->val, list});
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;

        while(!pq.empty()) {
            auto node = pq.top().second;
            pq.pop();
            curr -> next = node;
            curr = curr -> next;
            if(node -> next) pq.push({node->next->val, node->next});
        }

        return head->next;
    }
};


// The idea is to use a min heap to keep track of the smallest element among the k linked lists.
// We initially push the first element of each list into the heap. 
// Then, we repeatedly pop the smallest element from the heap and append it to the output linked list. 
// If the popped element has a next element, we push it into the heap.
// We continue this process until the heap is empty, which means all elements have been
// merged into the output linked list.

