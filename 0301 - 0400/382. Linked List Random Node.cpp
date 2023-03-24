// APPROACH 1


class Solution {
public:
    vector<int>vec;
    Solution(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int n=vec.size();
        int x=rand()%n;
        return vec[x];
    }
};






// APPROACH 2


class Solution {
public:
    ListNode* head;
    Solution(ListNode* _head) {
        head = _head;
    }
    
    int getRandom() {
        int res = 0, index = 0;
        auto p = head;
        while (p) {
            index ++ ;
            if (rand() % index == 0) res = p->val;
            p = p->next;
        }
        return res;
    }
};


