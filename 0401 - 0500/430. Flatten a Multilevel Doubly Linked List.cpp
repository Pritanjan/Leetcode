// APPROACH 1

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        vector<Node*> nodeList;
        dfsSearch(temp, nodeList);
        if (nodeList.size() > 0) {
            for (Node* node : nodeList) {
                node->prev = temp;
                node->next = nullptr;
                node->child = nullptr;
                temp->next = node;
                temp = node;
            }
        }
        head->prev = nullptr;
        head->child = nullptr;
        return head;
    }
    
    void dfsSearch(Node* temp, vector<Node*>& nodeList) {
        if (temp != nullptr) {
            nodeList.push_back(temp);
            dfsSearch(temp->child, nodeList);
            dfsSearch(temp->next, nodeList);
        }
    }
};






// APPROACH 2

class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(!head)
        {
            return head;
        }
        Node *cur=head;
        Node *pcur;
        vector<Node*> node;
        while(cur||!node.empty())
        {
            if(!cur)
            {
                cur=node.back();
                node.pop_back();
                cur->prev=pcur;
                pcur->next=cur;
            }
            else if(cur->child)
            {
                if(cur->next)
                {
                node.push_back(cur->next);
                }
                cur->next=cur->child;
                cur->next->prev=cur;
                cur->child=NULL;
            }
            pcur=cur;
            cur=cur->next;
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
            if (cur->child) {
                Node* child_last = dfs(cur->child);
                next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                if (next) {
                    child_last->next = next;
                    next->prev = child_last;
                }
                cur->child = nullptr;
                last = child_last;
            } else {
                last = cur;
            }
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

            while (cur) {
                Node* next = cur->next;
                // If there are child nodes, then process the child nodes first
                if (cur->child) {
                    Node* child_last = dfs(cur->child);

                    next = cur->next;
                    // connect node to child
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    // If next is not empty, connect last to next
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // set child to null
                    cur->child = nullptr;
                    last = child_last;
                }
                else {
                    last = cur;
                }
                cur = next;
            }
            return last;
        };

        dfs(head);
        return head;
    }
};

