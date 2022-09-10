//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = head->val;
        while(head->next != NULL){
            ans = ans*2 + head->next->val;
            head = head->next;
        }
        return ans;
    }
};

// T.C. --> O(n)
// S.C. --> O(1)

// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/2103452/C%2B%2B-Solution-oror-With-Explaination
