// APPROACH 1 [ TLE ]

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return 1;
        ListNode* temp = head -> next;
        while(temp != NULL and temp != head) temp = temp -> next;
        return (temp == head);
    }
};





// APPRAOCH 2 [HASH MAP]
	
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // empty list
        if(head == NULL) return false;
        map<ListNode*, bool> visited;
        ListNode* temp = head;        
        while(temp != NULL) {
            // cycle is present 
            if(visited[temp] == true) return 1;    
	    // if(ump.find(temp) != ump.end()) return true;
            visited[temp] = true;
            temp = temp -> next;
        }       
        return false;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)





// APPROACH 3 [ FLOYD'S CYCLE DETECTION ALGORITHM OR FAST SLOW POINTER]

// the slow pointer takes one step at a time and, 
// the fast pointer takes two steps each time. 
// If they meet, it means there is a ring.
// If null there is no ring.

class Solution {
public:
    bool hasCycle(ListNode *head) {  
	// if head is NULL then return false;
        if(head == NULL || head->next == NULL) return false;	
	
	// making two pointers slow and fast and assignning them to head      
        ListNode* slow  = head;
        ListNode* fast = head;
        
	// till fast and fast -> next not reaches NULL
	// we will increment fast by 2 step and slow by 1 step
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;

	    // At the point if slow and fast are at same address
	    // this means linked list has a cycle in it.
            if(slow == fast) return true;
        }
	// if traversal reaches to NULL this means no cycle.
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


// OR 


class Solution {
public:
    bool hasCycle(ListNode *head) {
	// if head is NULL then return false;
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow  = head;
        ListNode* fast = head -> next;        
        while(slow != fast){
            if(fast == NULL || fast -> next == NULL) return false;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return true;
    }
};





// APPROACH 4 [ Move fast pointer by 3 steps each time, & slow pointer by 1 step each time]

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};






// APPROACH 4(ii) [ Move fast pointer by 4 steps each time, & slow pointer by 1 step each time]

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr && fast->next->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};





// APPROACH 4(iii) [ Move fast pointer by 5 steps each time, & slow pointer by 1 step each time]

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr && fast->next->next->next != nullptr && fast->next->next->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next -> next -> next -> next;
            
            if(slow == fast) return true;
        }
        return false;
    }
};






// APPROACH 4(iv) [ Move fast pointer by 3 steps each time, & slow pointer by 2 step each time]

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;        
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next -> next;            
            if(slow == fast) return true;
        }
        return false;
    }
};






// APPROACH 4(v) [ Move fast pointer by 4 steps each time, & slow pointer by 2 step each time]


class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;        
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr && fast->next->next->next != nullptr ) {
            slow = slow -> next -> next;
            fast = fast -> next -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};





// APPROACH 5 [ Store in the collection ]

// Storing the node in the set, each time it is stored to determine whether the 
// current node exists or not, if it exists, it means that there is a ring,
// and it directly returns true, else continue untill it reaches end of LL

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> set;	    
        while(head != nullptr) {
            // If the node is already in the set, it means there's a cycle.
            if(set.count(head)) return true;
            // Otherwise, add the current node to the set.
            set.insert(head);
            head = head -> next;
	}        
	return false;
    }
};





// APPROACH 6 [ Delete one by one ]

// A LL is deleted one by one from the head node, and the deletion is used to
// make his next pointer point to himself. 
// If there is no ring, delete them one by one from the beginning node,
// and finally it will definitely be deleted

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // If head is null or head's next is null, return false.
        if(head == nullptr || head -> next == nullptr) return false;
        // If head's next is head, there's a cycle.
        if(head -> next == head) return true;
        ListNode* nextNode = head -> next;
        // Set head's next to itself to "remove" it from the list.
        head -> next = head;
        // Recursively check the next node.
        return hasCycle(nextNode);
    }
};





// APPROACH 7 [ First reverse then comparison ]

// If there is a cycle, then after the linked list is reversed,
// the original head node and the reversed head node point must be the same

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // New linked list
        ListNode* newHead = nullptr;
        while(head != nullptr) {
            // Save the next node to be visited.
            ListNode* temp = head->next;
            // Make the visited node the new head of the new linked list.
            head->next = newHead;
            // Update the new linked list.
            newHead = head;
            // Move on to the next node in the original linked list.
            head = temp;
        }
        // Return the new linked list.
        return newHead;
    }

    bool hasCycle(ListNode* head) {
        ListNode* rev = reverseList(head);
        if (head != nullptr && head->next != nullptr && rev == head) return true; 
        return false;
    }
};






// A 8 - RRecursion with Stack

class Solution {
public:
    bool hasCycle(ListNode* head) {
        set<ListNode*> vis;
        stack<ListNode*> stk;

        while(head) {
            if(vis.count(head)) return true;
            stk.push(head);
            vis.insert(head);
            head = head -> next;
        }
        while(!stk.empty()) {
            stk.pop();
        }
        return false;
    }
};






// A 9


































// QUESTION 1 [ check cycle -> tail to head ]
// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTab=0
	
#include <bits/stdc++.h> 
bool isCircular(Node* head){
    // empty list
    if(head == NULL) return true;
    if(head -> next == NULL) return false;
    Node* temp = head;
    Node* temp1 = head;
    
    while(temp != NULL && temp1 != NULL and temp1 -> next != NULL) {
        temp = temp -> next;
        temp1 = temp1 -> next -> next;        
        if(temp == temp1) break;
    }       
    if(temp == temp1 and temp == head) return true;
    return false;
}

// T.C. --> O(N)
// S.C. --> O(1)





// QUESTION 1 -->   FINDING STARTING NODE OF THE LOOP

bool FCDA(ListNode *head) {  
    // if head is NULL then return false;
    if(head == NULL || head->next == NULL) return false;	
    // making two pointers slow and fast and assignning them to head      
    ListNode* slow  = head;
    ListNode* fast = head;
        
    // till fast and fast -> next not reaches NULL
    // we will increment fast by 2 step and slow by 1 step
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
	// At the point if slow and fast are at same address
	// this means linked list has a cycle in it.
        if(slow == fast) return true;
    }
    // if traversal reaches to NULL this means no cycle.
    return false;
}

bool getStartingNode(TreeNode* head){
    if(head == NULL) return NULL;
    TreeNode* meet = FCDA(head);
    TreeNode* slow = head;
    while(slow !- meet){
        slow = slow -> next;
        meet = meet -> next;
    }
    return slow;
}





// QUESTION 2 --> REMOVING LOOP FROM THE LL
// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0
// Detect and Remove Loop

Node* FCDA(Node *head) {  
    // if head is NULL then return false;
    if(head == NULL) return NULL;    
    
    // making two pointers slow and fast and assignning them to head      
    Node* slow = head;
    Node* fast = head;
        
    // till fast and fast -> next not reaches NULL
    // we will increment fast by 2 step and slow by 1 step
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;

        // At the point if slow and fast are at same address
        // this means linked list has a cycle in it.
        if(slow == fast) return slow;
    }
    // if traversal reaches to NULL this means no cycle.
    return NULL;
}




Node* getStartingNode(Node* head) {
     if(head == NULL)
         return NULL;
     
    Node* meet = FCDA(head);
    Node* slow = head;
    
    if(meet == NULL)
        return NULL;
    
    while(slow != meet){
        slow = slow -> next;
        meet = meet -> next;
    }
    return slow;
}


Node *removeLoop(Node *head){
    if(head == NULL) return NULL;
    Node* startofLoop = getStartingNode(head);
    if(startofLoop == NULL) return head;
    Node* temp = startofLoop;
    
    while(temp -> next != startofLoop){
        temp = temp -> next;
    }    
    temp -> next = NULL;
    return head;
}

// T.C. --> O(N)
// S.C. --> O(1)



