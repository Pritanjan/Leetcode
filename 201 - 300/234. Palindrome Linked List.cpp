//https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        if(head == NULL or head->next == NULL)
            return true;
        else{
            ListNode *temp = head;
            while(temp -> next != NULL){
                v.push_back(temp -> val);
                temp = temp -> next;
            }
            v.push_back(temp -> val);
        }
        
        int n = v.size();
        for(int i=0; i<n/2; i++){
            if(v[i] != v[n-i-1])
                return false;
        }
        return true;
    }
};



