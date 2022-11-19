// https://leetcode.com/problems/linked-list-cycle/
// COMPANY TAG AMAZON LINKEDIN MICROSOFT

// https://leetcode.com/problems/linked-list-cycle/discuss/2011503/Microsot

// APPRAOCH 1 HASH MAP
	
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // empty list
        if(head == NULL){
            return false;
        }
    
        map<ListNode*, bool> visited;
        ListNode* temp = head;
        
        while(temp != NULL) {
            // cycle is present 
            if(visited[temp] == true){
                return 1;           
            }
        
            visited[temp] = true;
        
            temp = temp -> next;
        
        }       
        return false;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)




// APPROACH 2
// FLOYD'S CYCLE DETECTION ALGORITHM

class Solution {
public:
    bool hasCycle(ListNode *head) {  
	// if head is NULL then return false;
        if(head == NULL || head->next == NULL)
         	return false;	
	
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
            if(slow == fast)
                return true;
        }
	// if traversal reaches to NULL this means no cycle.
        return false;
    }
};

Time Complexity : O(N)
Space Complexity : O(1)


// OR 

class Solution {
public:
    bool hasCycle(ListNode *head) {
		// if head is NULL then return false;
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode* ptr  = head;
        ListNode* ptr1 = head->next;
        
        while(ptr != ptr1){
            if(ptr1 == NULL || ptr1->next == NULL)
                return false;
            ptr = ptr->next;
            ptr1 = ptr1->next->next;
        }
        return true;
    }
};















// check cycle -> tail to head
// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTab=0
	
	
#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }
    if(head -> next == NULL){
        return false;
    } 
    
    Node* temp = head;
    Node* temp1 = head;
    
    while(temp != NULL && temp1 != NULL and temp1 -> next != NULL) {
        temp = temp -> next;
        temp1 = temp1 -> next -> next;
        
        if(temp == temp1)
            break;
    }   
    if(temp == temp1 and temp == head)
        return true;
    
    return false;
}



// T.C. --> O(N)
// S.C. --> O(1)




// FINDING STARTING NODE OF THE LOOP

bool FCDA(ListNode *head) {  
    // if head is NULL then return false;
    if(head == NULL || head->next == NULL)
        return false;	
	
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
        if(slow == fast)
            return true;
    }
	// if traversal reaches to NULL this means no cycle.
    return false;
}




bool getStartingNode(TreeNode* head){
     if(head == NULL)
         return NULL;
    
    TreeNode* meet = FCDA(head);
    TreeNode* slow = head;
    
    while(slow !- meet){
        slow = slow -> next;
        meet = meet -> next;
    }
    
    return slow;
}





// REMOVING LOOP FROM THE LL
// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0
// Detect and Remove Loop


/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/


Node* FCDA(Node *head) {  
    // if head is NULL then return false;
    if(head == NULL)
        return NULL;    
    
    // making two pointers slow and fast and assignning them to head      
    Node* slow  = head;
    Node* fast = head;
        
    // till fast and fast -> next not reaches NULL
    // we will increment fast by 2 step and slow by 1 step
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;

        // At the point if slow and fast are at same address
        // this means linked list has a cycle in it.
        if(slow == fast)
            return slow;
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
    if(head == NULL)
        return NULL;
    
    Node* startofLoop = getStartingNode(head);
    if(startofLoop == NULL)
        return head;
    Node* temp = startofLoop;
    
    while(temp -> next != startofLoop){
        temp = temp -> next;
    }
    
    temp -> next = NULL;
    return head;
}

// T.C. --> O(N)
// S.C. --> O(1)


