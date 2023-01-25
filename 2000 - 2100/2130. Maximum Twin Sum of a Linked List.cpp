/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // int i = 0;
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        int n = v.size();
        int mx = 0;
        for(int i=0; i<n/2; i++){
            mx = max(mx, v[i] + v[n-i-1]);
        }
        return mx;
    }
};

