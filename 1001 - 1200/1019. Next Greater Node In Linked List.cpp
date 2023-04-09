// APPROACH 1


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v, res;
        ListNode* node = head;
        
        // convert linked list to vector
        while(node) {
            v.push_back(node->val);
            node = node->next;
        }
        
        int n = v.size();
        stack<int> st;
        
        // initialize result array to 0
        res.resize(n, 0); 
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && v[st.top()] < v[i]) {
                res[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }        
        return res;
    }
};






// 1. First, the linked list is converted into a vector v.

// 2. A result vector res is created, which will store the next greater node value for each node
//    in the linked list. It is initialized to 0.

// 3. A stack st is used to keep track of the indices of the nodes whose next greater node is not
//    found yet.

// 4. We iterate through the vector v and for each element, we check if it is greater than the
//    element at the top of the stack. If it is, then we update the result array for the top 
//    element of the stack and pop it from the stack. We repeat this until the top element of 
//    the stack is greater than or equal to the current element.

// 5. We push the current index i onto the stack.

// 6. Finally, we return the result vector res.


// T.C. --> O(n), where n is the number of nodes in the linked list, 
// since we visit each node in the linked list exactly once and perform constant-time operations 
// on the stack. 
// S.C. --> O(n), since we store the linked list in a vector and the stack can have at most n elements






