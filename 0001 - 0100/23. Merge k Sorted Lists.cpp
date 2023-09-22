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


// OR


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        } 
        else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        while(n > 1) {
            int k = (n + 1) / 2;
            for(int i=0; i<n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }        
        return lists[0];
    }
};


// OR


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        } 
        else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];

        int mid = n / 2;
        vector<ListNode*> L(lists.begin(), lists.begin() + mid);
        vector<ListNode*> R(lists.begin() + mid, lists.end());

        ListNode* mergedL = mergeKLists(L);
        ListNode* mergedR = mergeKLists(R);

        return mergeTwoLists(mergedL, mergedR);
    }
};




// A4


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


// OR SAME AS ABOVE


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        for(ListNode* list : lists) {
            if(list) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(!pq.empty()) {
            ListNode* small = pq.top();
            pq.pop();
            curr->next = small;
            curr = curr->next;

            if (small->next) pq.push(small->next);
        }
        return dummy.next;
    }
};






// A 5 -  Brute-Force Approach with Optimization:

// Here, We iterates through each list and selecting the minimum element at each step. 
// While it's not the most efficient method, it's still a viable option for small values of k.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(true) {
            int mi = INT_MAX;
            int idx = -1;
            for(int i=0; i<k; ++i) {
                if(lists[i] && lists[i] -> val < mi) {
                    mi = lists[i] -> val;
                    idx = i;
                }
            }
            
            if(idx == -1) break;
            curr -> next = lists[idx];
            curr = curr -> next;
            lists[idx] = lists[idx] -> next;
        }        
        return dummy.next;        
    }
};






//  A 6 -  Parallel Merging - chat gpt
// If we have access to multi-threading or parallel processing, we can split the k lists into
// smaller groups and merge them in parallel, then merge the results from each group sequentia

class Solution {
public:        
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        } 
        else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }

    ListNode* parallelMergeKLists(vector<ListNode*>& lists, int L, int R) {
        if(L == R) return lists[L];

        int mid = L + (R - L) / 2;
        ListNode* leftList = parallelMergeKLists(lists, L, mid);
        ListNode* rightList = parallelMergeKLists(lists, mid + 1, R);
        
        return mergeTwoLists(leftList, rightList);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return nullptr;
        return parallelMergeKLists(lists, 0, k-1);
    }
};






// A 7 -  Using a Balanced Binary Search Tree:

// Use multiset or multimap (based on balanced BST), we can use them to maintain the sorted order
// of elements efficiently. 
// Inserting elements from all lists into the tree and then constructing the final merged list
// from the tree's elements can be a viable approach.

struct CompareNodes {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val < b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, CompareNodes> tree;
        for (ListNode* list : lists) {
            while (list) {
                tree.insert(list);
                list = list->next;
            }
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        for (const ListNode* node : tree) {
            current->next = const_cast<ListNode*>(node);
            current = current->next;
        }
        
        return dummy.next;
    }
};





