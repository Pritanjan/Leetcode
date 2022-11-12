// Sort linked list of 0s 1s 2s
// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

// Count the number of occurrences, then update the linked list.
// Separate each node and reconnect.


void insertAtTail(Node* tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head) {
    Node* zerohead = NULL;
    Node* zerotail = zerohead;
    Node* onehead = NULL;
    Node* onetail = onehead;
    Node* twohead = NULL;
    Node* twotail = twohead;

    Node* curr = head;
    
    //create seperate list 0s, 1s and 2s
    while(curr != NULL){
        int val = curr -> data;
        if(val == 0)
            insertAtTail(zerotail, curr);
        else if(val == 1)
            insertAtTail(onetail, curr);
        else if(val == 2)
            insertAtTail(twotail, curr);
        
        curr = curr -> next;
    }
    
    // merge 3 LL
    
    // 1s is not empty
    if(onehead -> next != NULL)
        zerotail -> next = onehead;
    else
        // 1s is empty 
        zerotail -> next = twohead -> next;
    
    onetail -> next = twohead -> next;
    twotail -> next = NULL;
    
    // setup head
    head = zerohead -> next;

    // delete dummy node
    delete zerohead;
    delete onehead;
    delete twohead;
}

// T.C. --> O(n)
// S.C. --> O(1)







