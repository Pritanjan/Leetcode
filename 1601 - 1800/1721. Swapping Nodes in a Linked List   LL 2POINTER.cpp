//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int> nums;
        
        // STEP 1 :- CONVERT LINKED_LIST INTO ARRAY 
        while(head!= NULL){
            nums.push_back(head -> val);
            head = head ->next;
        }
        
        // STEP 2 :- FINDING VALUE TO BE SWAPPED
        int n = nums.size() ;
        // cout<<nums[k-1]<<nums[n-k]<<"\n";
        swap(nums[k-1], nums[n-k]);
        
        // STEP 3 :- CONVERTING BACK ARRAY TO LINKED_LIST
        ListNode* ans = new ListNode(NULL);
        head = ans;
        for(int i=0; i<n; i++){
            ans -> next = new ListNode(nums[i]);
            ans = ans -> next;
        }
        
        return head ->next;
        
    }
};
