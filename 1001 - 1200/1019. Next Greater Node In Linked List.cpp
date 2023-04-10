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







// APPROACH 2

class Solution {
	int len = 0;
	// reverse linked list
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			len++;
		}
		return prev;
	}
public:
	vector<int> nextLargerNodes(ListNode* head) {
		if (!head) return {};
		if (!head->next) return{ 0 };
		ListNode* p = reverseList(head);
		vector<int> ans(len);
		stack<int> s;
		while (p != nullptr)
		{
			while (!s.empty() && s.top() <= p->val)
				s.pop();
			ans[--len] = s.empty() ? 0 : s.top();
			s.push(p->val);
			p = p->next;
		}
		return ans;
	}
};






// APPROACH 3

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        // in each pair, first is the value, second is the index
        stack<pair<int, int>> S;
        // index of the current node
        int idx = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
            // for the current node, there is no node that is larger than it
            res.emplace_back(0);
            // pop out all the node that is smaller than current value
            for (; !S.empty() && S.top().first < cur->val; S.pop()) {
                // update the result
                res[S.top().second] = cur->val;
            }
            // push the current node into the stack
            S.push(make_pair(cur->val, idx));
            // move to next node
            ++idx;
        }
        return res;
    }
};







// APPROACH 4

// 1. Traverse through the linked list head, and use an array values to store the values of nodes.

// 2. Initialize an array answer with the same size as values and an empty stack stack to store the 
//    previous indexes.

// 3. Iterate over values, before we push each index i to stack :-
//    (i)  If the value represented by the top element of stack (let's call it values[smaller]) is 
//         smaller than values[i], it means that values[i] is values[smaller]'s larger value. 
//         So we pop smaller from the stack, update answer[smaller] = values[i] and repeat this step.
//    (ii) Otherwise, it means there is no value smaller than values[i], we add values[i] to stack and 
//         repeat step 3.


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        
        int n = int(values.size());
        stack<int> iStack;
        vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            while (!iStack.empty() && values[iStack.top()] < values[i]) {
                int smaller = iStack.top();
                iStack.pop();
                answer[smaller] = values[i];
            }
            iStack.push(i);
        }
        
        return answer;
    }
};
