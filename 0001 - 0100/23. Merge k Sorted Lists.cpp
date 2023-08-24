// APPROACH 1 : Brute Force

// Traverse all the linked lists and collect the values of the nodes into an array.
// Sort and iterate over this array to get the proper value of nodes.
// Create a new sorted linked list and extend it with the new nodes.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for(auto l : lists) {
            while(l) {
                nodes.push_back(l -> val);
                l = l -> next;
            }
        }

        sort(nodes.begin(), nodes.end());
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        for(auto x : nodes) {
            point -> next = new ListNode(x);
            point = point -> next;
        }        
        return head -> next;
    }
};

// Time complexity : O(N log ⁡N) where N is the total number of nodes.
// Collecting all the values costs O(N)) time.
// A stable sorting algorithm costs O(N log⁡ N) time.
// Iterating for creating the linked list costs O(N) time.

// Space complexity : O(N).
// Sorting cost O(N) space (depends on the algorithm you choose).
// Creating a new linked list costs O(N) space.






// APPROACH 2

// The idea is to use a min heap to keep track of the smallest element among the k linked lists.
// We initially push the first element of each list into the heap. 
// Then, we repeatedly pop the smallest element from the heap and append it to the output linked list. 
// If the popped element has a next element, we push it into the heap.
// We continue this process until the heap is empty, which means all elements have been
// merged into the output linked list.

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


// OR


struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(ListNode* list : lists) {
            if(list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(!pq.empty()) {
            ListNode* small = pq.top();
            pq.pop();
            curr -> next = small;
            curr = curr -> next;
            
            if(small -> next) pq.push(small -> next);
        }        
        return dummy.next;
    }
};






// A3

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amt = lists.size();
        int interval = 1;

        while(interval < amt) {
            for(int i= 0; i<amt- interval; i+=interval * 2) {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return amt > 0 ? lists[0] : nullptr;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            }
            else {
                point->next = l2;
                l2 = l1;
                l1 = point->next->next;
            }
            point = point->next;
        }

        if(!l1) point -> next = l2;
        else point -> next = l1;
        return head->next;
    }
};






// A4
