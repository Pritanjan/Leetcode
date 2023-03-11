class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        // find the middle node of the list
        ListNode* prev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
 
        // create a new node for the middle value
        TreeNode* root = new TreeNode(slow -> val);
        
        // recursively build the left and right subtrees
        if(prev != NULL) prev -> next = NULL;
        else head = NULL;

        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow -> next);

        return root;
    }
};



// Traverse the list to get the middle element and make that the root. left side of the list 
// forms left sub-tree and right side of the middle element forms the right sub-tree.




// The first step is to check if the head of the linked list is NULL, in which case the function 
// returns NULL, as there is no tree to be created.

// Then, it uses the slow and fast pointers method to find the middle of the linked list,
// similar to the previous explanation. The prev variable keeps track of the node before
// the slow pointer, which will be used later to break the linked list into two parts.

// Once the middle of the linked list is found, a new TreeNode is created with the value 
// of the middle node. The middle node is the root of the BST.

// Then, the linked list is broken into two parts, the left part and the right part.
// The left part is the nodes before the middle node, and the right part is the nodes after
// the middle node.

// The left part of the linked list is recursively passed as the left child of the root node
// and the right part of the linked list is recursively passed as the right child of the root node.

// Finally, the root node is returned as the result of the function.

// This code uses the property of a BST that left child node is always smaller than the right
// child node and recursively constructs left and right sub-tree until the last node.











class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        // count the number of nodes in the list
        int cnt = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            cnt++;
            cur = cur -> next;
        }
        
        // create an array to store the sorted values
        vector<int> values(cnt);
        cur = head;
        for(int i=0; i<cnt; i++){
            values[i] = cur -> val;
            cur = cur -> next;
        }
        
        // recursively build the tree
        return buildTree(values, 0, cnt - 1);
    }
    
    TreeNode* buildTree(vector<int>& values, int L, int R) {
        if(L > R) return nullptr;

        // find the middle index
        int mid = (L + R) / 2;
        
        // create a new node with the middle value
        TreeNode* root = new TreeNode(values[mid]);
        
        // recursively build the left and right subtrees
        root -> left =  buildTree(values, L, mid - 1);
        root -> right = buildTree(values, mid + 1, R);
        
        return root;
    }
};




