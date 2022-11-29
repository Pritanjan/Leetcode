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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* ptr = head;
        int len = 0;
        
        while(ptr != NULL){
            ptr = ptr -> next;
            len++;
        }
        
        int width = len / k;
        int rem = len % k;
        
        ptr = head;
        vector<ListNode*> ans;

        while(ptr != NULL){
            ans.push_back(ptr);
            int currlen = 1;
            while(currlen < width){
                ptr = ptr -> next;
                currlen++;
            }
            
            if(len > k and rem > 0){
                ptr = ptr -> next;
                rem--;
            }
            ListNode* temp = ptr -> next;
            ptr -> next = NULL;
            ptr = temp;
        }
                
        while(len < k){
            ans.push_back(NULL);
            len++;
        }
        return ans;
                
    }
};






// ListNode[] ans = new ListNode[k];
