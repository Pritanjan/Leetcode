// APPROACH 1


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        if(head == NULL or head->next == NULL) return true;
        else{
            ListNode *temp = head;
            while(temp -> next != NULL){
                v.push_back(temp -> val);
                temp = temp -> next;
            }
            v.push_back(temp -> val);
        }
        
        int n = v.size();
        for(int i=0; i<n/2; i++){
            if(v[i] != v[n-i-1])
                return false;
        }
        return true;
    }
};


// T.C. --> O(N) As we iterate over whole LL
// S.C. --> O(N) As we create an array of size N





// APPROACH 2

class Solution {
private:
    bool checkPali(vector<int> &v) {
        int n = v.size();
        int L = 0;
        int R = n-1;
        
        while(L <= R){
            if(v[L] != v[R]) return 0;
            L++;
            R--;
        }
        return L;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        return checkPali(v);
    }  
};



// APPROACH 3 [ FIND MID AND COMPARE BOTH PART OF LL ]

class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL and fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return true;
        
        // s1 find mid
        ListNode* mid = getMid(head);
        
        // s2 reverse ll after middle
        ListNode* temp = mid -> next;
        mid -> next = reverse(temp);
     
        // compare both half
        ListNode* head1 = head;
        ListNode* head2 = mid -> next;
        
        while(head2 != NULL){
            if(head1 -> val != head2 -> val)
                return false;
            head1 = head1 -> next;
            head2 = head2 -> next;
            
        }
        
        return true;
    }
};


// t.c. O(N)
// s.c. O(1)





