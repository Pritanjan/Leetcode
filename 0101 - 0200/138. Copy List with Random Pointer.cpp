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



