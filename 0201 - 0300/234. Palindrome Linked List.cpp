// APPROACH 1

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        if(head == NULL or head->next == NULL) return true;
        else {
            ListNode *temp = head;
            while(temp -> next != NULL){
                v.push_back(temp -> val);
                temp = temp -> next;
            }
            v.push_back(temp -> val);
        }        
        int n = v.size();
        for(int i=0; i<n/2; i++){
            if(v[i] != v[n-i-1]) return false;
        }
        return true;
    }
};

// T.C. --> O(N) As we iterate over whole LL
// S.C. --> O(N) As we create an array of size N


// OR


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL) {
            arr.push_back(head -> val);
            head = head -> next;
        }

        for(int i=0; i<arr.size()/2; i++) {
            if(arr[i] != arr[arr.size()-i-1]) return false;
        }            
        return true;
    }
};






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
        if(head == NULL or head -> next == NULL) return true;
        
        // s1 find mid
        ListNode* mid = getMid(head);
        
        // s2 reverse ll after middle
        ListNode* temp = mid -> next;
        mid -> next = reverse(temp);
     
        // compare both half
        ListNode* head1 = head;
        ListNode* head2 = mid -> next;
        while(head2 != NULL){
            if(head1 -> val != head2 -> val) return false;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }        
        return true;
    }
};

// t.c. O(N)
// s.c. O(1)





// APPROACH 4

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        // Find the end of first half and reverse second half.
        ListNode* ptr = endOfFirstHalf(head);                // firstHalfEnd
        ListNode* ptr1 = reverseList(ptr->next);             // secondHalfStart

        // Check whether or not there is a palindrome.
        ListNode* p1 = head;
        ListNode* p2 = ptr1;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }        

        // Restore the list and return the result.
        ptr->next = reverseList(ptr1);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};





// APPROACH 5 Using a Stack
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        while(curr) {
            s.push(curr -> val);
            curr = curr -> next;
        }

        curr = head;
        while(!s.empty()) {
            if(s.top() != curr -> val) return false;
            s.pop();
            curr = curr -> next;
        }
        return true;
    }
};


// OR


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        stack<int> stk;
        ListNode* slow = head;
        ListNode* fast = head;

        // Push the first half of the list onto the stack
        while(fast && fast->next) {
            stk.push(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // If the list has an odd length, skip the middle element
        if(fast) slow = slow -> next;

        // Compare the second half of the list with the reversed first half
        while(slow) {
            if(stk.top() != slow -> val) return false;
            stk.pop();
            slow = slow -> next;
        }
        return true;
    }
};





// APPROACH 6 RECURSON

class Solution {
public:
    bool recursion(ListNode* &L, ListNode* R) {
        if(!R) return true;
        bool isPal = recursion(L, R -> next);
        if(!isPal) return false;

        bool currentIsPal = (L -> val == R -> val);
        L = L -> next;  
        return currentIsPal;
    }

    bool isPalindrome(ListNode* head) {
        return recursion(head, head);
    }
};






// APPROACH 7 [ Reverse the Second Half of the Linked List  ]

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare the reversed second half with the first half
        while(prev) {
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};






// OR
// Reversing the First Half

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            ListNode* temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }
        
        // Odd number of nodes, skip the middle node
        if(fast != nullptr) slow = slow -> next;
        
        while(prev != nullptr && slow != nullptr) {
            if(prev->val != slow->val) return false;
            prev = prev -> next;
            slow = slow -> next;
        }        
        return true;
    }
};



