// A 1

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode*> umap;
        umap[0] = root;
        int sum = 0;
        while (head != NULL) {
            sum += head->val;
            if (umap.find(sum) != umap.end()) {
                ListNode* prev = umap[sum];
                ListNode* start = prev;         

                int aux = sum;
    
                while (prev != head) {
                    prev = prev->next;
                    aux += prev->val;
                    if (prev != head) {
                        umap.erase(aux);
                    }
                }
                start->next = head->next;
            }
            else if (umap.find(sum) == umap.end()) {
                umap[sum] = head;
            }
            head = head->next;
        }
        return root->next;
    }
};





// 
class Solution {
public:
    void sanatizemap(ListNode* head, unordered_map<int, ListNode*>& mp, int csum) {
        int temp = csum;
        while (true) {
            temp += head->val;
            if (temp == csum) break;
            mp.erase(temp);
            head = head->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == NULL || head->next == NULL && head->val == 0) return 0;

        unordered_map<int, ListNode*> mp;
        auto it = head;
        int csum = 0;
        while (it) {
            csum += it->val;
            if (csum == 0) {
                head = it->next;
                mp.clear();
            }
            else if (mp.find(csum) != mp.end()) {
                sanatizemap(mp[csum]->next, mp, csum);
                mp[csum]->next = it->next;
            }
            else mp[csum] = it;
            it = it->next;
        }
        return head;
    }
};







// Delete continuous nodes with sum K from a given linked list

// Approach:  

// 1. Append Node with value zero at the starting of the linked list.
// 2. Traverse the given linked list.
// 3. During traversal store the sum of the node value till that node with the reference
//    of the current node in an unordered_map.
// 4. If there is Node with value (sum – K) present in the unordered_map then delete all 
//    the nodes from the node corresponding to value (sum – K) stored in map to the
//    current node and update the sum as (sum – K).
// 5. If there is no Node with value (sum – K) present in the unordered_map, 
//    then stored the current sum with node in the map.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// A Linked List Node
struct ListNode {
	int val;
	ListNode* next;

	// Constructor
	ListNode(int x) : val(x), next(NULL)
};

// Function to create Node
ListNode* getNode(int data) {
	ListNode* temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = data;
	temp->next = NULL;
	return temp;
}

// Function to print the Linked List
void printList(ListNode* head) {
	while(head->next) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val;
}

// Function that removes continuous nodes whose sum is K
ListNode* removeZeroSum(ListNode* head, int K) {
	// Root node initialise to 0
	ListNode* root = new ListNode(0);

	// Append at the front of the given Linked List
	root->next = head;

	// Map to store the sum and reference of the Node
	unordered_map<int, ListNode*> umap;
	umap[0] = root;

	// To store the sum while traversing
	int sum = 0;

	// Traversing the Linked List
	while(head != NULL) {

		// Find sum
		sum += head->val;

		// If found value with (sum - K)
		if(umap.find(sum - K) != umap.end()) {
			ListNode* prev = umap[sum - K];
			ListNode* start = prev;			

			// Update sum
			sum = sum - K;
			int aux = sum;
			// Traverse till current head
			while (prev != head) {
				prev = prev->next;
				aux += prev->val;
				if (prev != head) {
					umap.erase(aux);
				}
			}

			// Update the start value to
			// the next value of current head
			start->next = head->next;
		}

		// If (sum - K) value not found
		else if (umap.find(sum) == umap.end()) {
			umap[sum] = head;
		}

		head = head->next;
	}

	// Return the value of updated
	// head node
	return root->next;
}

// Driver Code
int main() {
	// head Node
	ListNode* head;

	// Create Linked List
	head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(-3);
	head->next->next->next = getNode(3);
	head->next->next->next->next = getNode(1);

	// Given sum K
	int K = 5;

	// Function call to get head node
	// of the updated Linked List
	head = removeZeroSum(head, K);

	// Print the updated Linked List
	if (head != NULL)
		printList(head);
	return 0;
}

// Output
// 1 -> 2 -> -3 -> 3 -> 1
// Time Complexity : O(N), where N is the number of Node in the Linked List. 
// Space Complexity: O(N), where N is the number of Node in the Linked List.
