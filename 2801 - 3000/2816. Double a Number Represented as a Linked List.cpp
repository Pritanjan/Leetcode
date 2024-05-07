// APPROACH 1

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* newHead = nullptr;
        curr = nullptr;
        int carry = 0;

        while(prev) {
            int dob = prev->val * 2 + carry;
            carry = dob / 10;

            if(!newHead) {
                newHead = new ListNode(dob % 10);
                curr = newHead;
            } 
            else {
                curr -> next = new ListNode(dob % 10);
                curr = curr-> next;
            }
            prev = prev ->next;
        }

        if(carry > 0) curr -> next = new ListNode(carry);
        
        ListNode* res = nullptr;
        curr = newHead;
        while(curr) {
            ListNode* next = curr -> next;
            curr ->next = res;
            res = curr;
            curr = next;
        }
        return res;
    }
};



// OR



class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head -> val);
            head = head -> next;
        }
        
        int carry = 0;
        for(int i=v.size()-1; i>=0; i--) {
            v[i] = 2 * v[i] + carry;
            carry = v[i] / 10;
            v[i] = v[i] % 10;
        }
        
        if (carry) v.insert(v.begin(), carry);
        ListNode* ans = new ListNode(v[0]);
        ListNode* curr = ans;
        for(int i=1; i<v.size(); i++) {
            curr -> next = new ListNode(v[i]);
            curr = curr -> next;
        }
        return ans;
    }
};






// APPROACH 2

class Solution {
public:
    int dfs(ListNode* head) {
        if(head == nullptr) return 0;
        head -> val = head -> val << 1 |dfs(head -> next);
        if(head -> val < 10)return 0;
        else {
            head -> val -= 10;
            return 1;
        }
    }

    ListNode* doubleIt(ListNode* head) {
        if(dfs(head)) head =new ListNode(1, head);
        return head;
    }
};






// A 3 - Using Stack

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Initialize a stack to store the values of the linked list
        stack<int> values;
        int val = 0;

        // Traverse the linked list and push its values onto the stack
        while (head != nullptr) {
            values.push(head->val);
            head = head->next;
        }

        ListNode* newTail = nullptr;

        // Iterate over the stack of values and the carryover
        while (!values.empty() || val != 0) {
            // Create a new ListNode with value 0 and the previous tail as its next node
            newTail = new ListNode(0, newTail);
            
            // Calculate the new value for the current node
            // by doubling the last digit, adding carry, and getting the remainder
            if (!values.empty()) {
                val += values.top() * 2;
                values.pop();
            }
            newTail->val = val % 10;
            val /= 10;
        }

        // Return the tail of the new linked list
        return newTail;
    }
};





// A 4 - Reverse List

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Reverse the linked list
        ListNode* rev = reverseList(head);

        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode* curr = rev, *prev = nullptr;

        // Traverse the reversed linked list
        while (curr != nullptr) {
            // Calculate the new value for the current node
            int newValue = curr -> val * 2 + carry;
            // Update the current node's value
            curr -> val = newValue % 10;
            // Update carry for the next iteration
            if (newValue > 9) carry = 1;
            else carry = 0;
        
            // Move to the next node
            prev = curr;
            curr = curr -> next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            prev -> next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode* res = reverseList(rev);
        return res;
    }

    // Method to reverse the linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr, *curr = node, *nextNode;

        // Traverse the original linked list
        while (curr != nullptr) {
            // Store the next node
            nextNode = curr -> next;
            // Reverse the link
            curr -> next = prev;
            // Move to the next nodes
            prev = curr;
            curr = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return prev;
    }
};
