// APPROACH 1

class Solution {
public:
    void dfs(Node* temp, vector<Node*>& node) {
        if (temp != nullptr) {
            node.push_back(temp);
            dfs(temp -> child, node);
            dfs(temp -> next,  node);
        }
    }
    
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;        
        Node* temp = head;
        vector<Node*> node;
        dfs(temp, node);
        
        if(node.size() > 0) {
            for(Node* node : node) {
                node -> prev  = temp;
                node -> next  = nullptr;
                node -> child = nullptr;
                temp -> next  = node;
                temp = node;
            }
        }
        head -> prev  = nullptr;
        head -> child = nullptr;
        return head;
    }
};





// APPROACH 2

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node *cur = head;
        Node *pcur;
        vector<Node*> node;
        while(cur || !node.empty()) {
            if(!cur) {
                cur = node.back();
                node.pop_back();
                cur -> prev = pcur;
                pcur -> next = cur;
            }
            else if(cur -> child) {
                if(cur -> next) node.push_back(cur -> next);
                cur -> next = cur -> child;
                cur -> next -> prev = cur;
                cur -> child = NULL;
            }
            pcur = cur;
            cur = cur -> next;
        }        
        return head;
    }
};





// APPROACH 3

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        dfs(head);
        return head;
    }
    
    Node* dfs(Node* node) {
        Node* cur = node;
        Node* last = nullptr;
        
        while (cur) {
            Node* next = cur->next;
            if(cur->child) {
                Node* child_last = dfs(cur->child);
                next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                if(next) {
                    child_last->next = next;
                    next->prev = child_last;
                }
                cur->child = nullptr;
                last = child_last;
            } 
            else last = cur;
            cur = next;
        }        
        return last;
    }
};


// OR


class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> dfs = [&](Node* node) {
            Node* cur = node;
            // record the last node of the linked list
            Node* last = nullptr;

            while(cur) {
                Node* next = cur->next;
                // If there are child nodes, then process the child nodes first
                if(cur->child) {
                    Node* child_last = dfs(cur->child);
                    next = cur->next;
                    // connect node to child
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    // If next is not empty, connect last to next
                    if(next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // set child to null
                    cur->child = nullptr;
                    last = child_last;
                }
                else last = cur;
                cur = next;
            }
            return last;
        };
        dfs(head);
        return head;
    }
};






// APPROACH 4

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tmp = head;
        stack<Node*> st;
        while(tmp){
            if(tmp->child){
                if(tmp->next) st.push(tmp->next);
                tmp->next = tmp->child;
                tmp->child->prev = tmp;
                tmp->child = NULL;
            }
            if(!tmp->next and !st.empty()) {
                tmp->next = st.top();
                st.top()->prev = tmp;
                st.pop();
            }
            tmp = tmp->next;
        }
        return head;
    }
};





// APPROACH 5

























// Flattening a Linked List
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if(a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } 
    else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    return result;
}

Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}

