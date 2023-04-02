// APPROACH 1

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* p = head;
        while(p != NULL) {
            Node* q = new Node(p->val);
            map[p] = q;
            p = p->next;
        }
        p = head;
        Node* q = map[p];
        while(p != NULL) {
            q->next = map[p->next];
            q->random = map[p->random];
            q = q->next;
            p = p->next;
        }
        return map[head];
    }
};





// APPROACH 2

class Solution {
    unordered_map<Node*,Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* newnode=new Node(head->val);
        m[head]=newnode;
        newnode->next=copyRandomList(head->next);
        if(head->random)newnode->random=m[head->random];
        return newnode;
    }
};






// APPROACH 3

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        // Connect the original linked list and its corresponding "mirror linked list" in series
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        
        // According to the random pointer of each node of the original linked list, through the connection between the original linked list and the new linked list, set the random pointer of each node of the new linked list
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }

        // Concatenate the new linked list
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};



