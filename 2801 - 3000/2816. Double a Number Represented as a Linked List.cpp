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


