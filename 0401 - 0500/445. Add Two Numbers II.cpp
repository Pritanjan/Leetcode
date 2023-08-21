// SAME AS LC Q 2 Add Two Numbers II

// APPROACH 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while(head){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = reverseList(l1);
        ListNode* l = reverseList(l2);
        int sum = 0;
        ListNode* temp = new ListNode(0) ;
        ListNode* ans = temp;
        
        // ListNode* rtn = new ListNode((l1->val + l2->val) % 10);
        while(p or l) {
            if(p) {
                sum += p -> val;
                p = p -> next;
            }
            if(l) {
                sum += l -> val;
                l = l -> next;
            }
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            
            if(sum > 9) sum = 1;
            else sum = 0;
        }
        if(sum) temp -> next = new ListNode(sum);
        return reverseList(ans -> next);
    }
};






// APPROACH 2 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while(l1 != nullptr) {
            stk1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2 != nullptr) {
            stk2.push(l2 -> val);
            l2 = l2 -> next;
        }

        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while(!stk1.empty() || !stk2.empty()) {
            if(!stk1.empty()) {
                totalSum += stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()) {
                totalSum += stk2.top();
                stk2.pop();
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }
        return carry == 0 ? ans->next : ans;
    }
};  






// APPROACH 3 

