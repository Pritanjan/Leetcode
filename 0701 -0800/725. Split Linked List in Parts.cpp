// A 1

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






// A 2 - Count and Split
// It involves counting the total number of nodes in the linked list, 
// calculating the size of each part, and then splitting the list accordingly.

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int cnt = 0;
        ListNode* curr = head;
        
        // Count the total number of nodes in the linked list
        while(curr) {
            cnt++;
            curr = curr -> next;
        }        
        int size = cnt / k;
        int extra = cnt % k;
        curr = head;
        
        for(int i=0; i<k; i++) {
            ListNode* tmp = curr;
            int size1 = size + (extra-- > 0 ? 1 : 0);
            for(int j=0; j<size1-1; j++) {
                if(curr) curr = curr -> next;
            }
            
            if(curr) {
                ListNode* tmp = curr -> next;
                curr -> next = nullptr;
                curr = tmp;
            }
            res.push_back(tmp);
        }        
        return res;
    }
};






// A 3 -  Using an Array
// First convert the linked list into an array of nodes, making it easier to split into k parts.

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        vector<ListNode*> v; // Convert linked list to an array of nodes

        ListNode* curr = head;
        int cnt = 0;
        while(curr) {
            v.push_back(curr);
            curr = curr -> next;
            cnt++;
        }

        int size = cnt / k;
        int extra = cnt % k;
        int i = 0;
        for(int j=0; j<k; j++) {
            int cnt1 = size + (extra-- > 0 ? 1 : 0);
            if(cnt1 > 0) {
                res[j] = v[i];
                ListNode* tail = v[i + cnt1 - 1];
                tail -> next = nullptr;
                i += cnt1;
            }
        }
        return res;
    }
};






// A 4
