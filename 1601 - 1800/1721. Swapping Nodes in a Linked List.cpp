// APPROACH 1


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







// APPROACH 2 [ 2_POINTER ]


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head; 
        ListNode* ptr2 = head;
        ListNode *k1  = NULL;
        
        while(--k){
            ptr1 = ptr1 -> next;
        }
        
        k1 = ptr1;
        ptr1 = ptr1 ->next;
        while(ptr1){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        swap(k1 -> val, ptr2 -> val);
        
        return head;
    }
};



