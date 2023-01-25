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

