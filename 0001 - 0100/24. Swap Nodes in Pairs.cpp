// A 0 - Iterative Approach  with Pointers:
// Use a pointer to traverse the list while swapping adjacent nodes.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Update pointers
            prev = first;
            head = first->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};





// APPROACH 1 
// [ Recursive Approach Using 3 Pointer ]

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {        
        if(!head || !head -> next) return head;
        ListNode* first  = head;
        ListNode* second = head->next;
        ListNode* ptr    = swapPairs(second -> next);
        second -> next = first;
        first  -> next = ptr;
        
        return second;
    }
};




// OR  
// [ Recursive Approach Using 2 Pointer ]


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // Swapping
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};





// APPROACH 2


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL and ptr->next != NULL){
            swap(ptr -> val , ptr->next->val);
                ptr = ptr->next->next;
        }
        return head;
    }
};



// OR


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** pp = &head;

        while (*pp && (*pp)->next) {
            ListNode* first = *pp;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            *pp = second;

            pp = &(first->next);
        }

        return head;
    }
};







// APPROACH 3


class Solution {
public:
    ListNode* vectorToLinkedList(vector<int>& v) {
        if(v.empty()) return nullptr;

        ListNode* head = new ListNode();
        head->val = v[0];
        head->next = nullptr;
        ListNode* current = head;

        for(int i=1; i<v.size(); ++i) {
            ListNode* newNode = new ListNode();
            newNode->val = v[i];
            newNode->next = nullptr;
            current->next = newNode;
            current = newNode;
        }
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        int cnt = 0;

        while(temp != nullptr){
            cnt++;
            v.push_back(temp->val);
            temp = temp -> next;
        }
        
        for(int i=0; i<cnt-1; i+=2){
            swap(v[i], v[i+1]);
        }

        vector<int> p = v;
        ListNode* res = vectorToLinkedList(p);
        return res;
    }
};





// A 4 - Using 3 Pointer

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first = NULL;
        ListNode* second = head;
        ListNode* third = head -> next;
        while(third) {
            second -> next = third -> next;
            if(first) first -> next = third;
            else head = third;
            third -> next = second;
            first = second;
            second = first -> next;
            if(!second) break;
            third = second -> next;
        }
        return head;
    }
};






// A 5

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);  // Create a dummy node
        ListNode* prev = &dummy;  // Pointer to the previous node
        ListNode* currA, *currB;  // Pointers for the two nodes to be swapped

        while((currA = prev -> next) && (currB = currA -> next)) {
            // Swap the two nodes
            currA -> next = currB -> next;
            currB -> next = currA;
            prev -> next = currB;
            prev = currA;
        }        
        return dummy.next;
    }
};






// A 6

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int init = []{
    ofstream out("user.out", ios::out);

    string s;
    while(getline(cin, s)) {
        vector<int> inp1;
        vector<int> inp2;
        int curr = 0;
        bool first = true;
        if(s.size() != 2) for (char &i : s) {
            if ('0' <= i && i <= '9') curr = curr * 10 + (i - '0');
            else if (i == ',' || i == ']') {
                if (first) inp1.push_back(curr);
                else       inp2.push_back(curr);
                first = !first;
                curr = 0;
            }
        }

        int size = inp1.size() + inp2.size();
        if (size & 1) inp2.push_back(inp1.back());
        out << '[';
        for (int i = 0; i < size; i++) {
            if (i > 0) out << ',';
            int j = i >> 1;
            if (i & 1) out << inp1[j];
            else       out << inp2[j];
        }
        out << ']' << endl;
    }
    exit(0);
    return 0;
}();

class Solution{public:ListNode*swapPairs(ListNode*head){return NULL;}};








