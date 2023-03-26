class MyLinkedList {
public:
    // Define the linked list node structure
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // The head node defined here is a virtual head node, not a real linked list head node
        _size = 0;
    }

    // Obtain the value of the index node. If the index is an illegal value, return -1 directly. Note that the index starts from 0, and the 0th node is the head node
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){ //If --index will fall into an infinite loop
            cur = cur->next;
        }
        return cur->val;
    }

    // Insert a node at the front of the linked list. After the insertion is complete, the newly inserted node is the new head node of the linked list.
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // Add a node at the end of the linked list
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // Insert a new node before the index node, for example, if the index is 0, then the newly inserted node is the new head node of the linked list.
    // If index is equal to the length of the linked list, it means that the newly inserted node is the end node of the linked list
    // If index is greater than the length of the linked list, return empty
    // If index is less than 0, insert the node at the head
    void addAtIndex(int index, int val) {

        if(index > _size) return;
        if(index < 0) index = 0;        
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // Delete the index node, if the index is greater than or equal to the length of the linked list, return directly, note that the index starts from 0
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // print LL
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 
 
 
 
 
 
 
 
 
