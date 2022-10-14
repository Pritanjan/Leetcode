//https://leetcode.com/problems/middle-of-the-linked-list/discuss/2428799/C%2B%2B-2-Solution-With-Explanation

//https://leetcode.com/problems/middle-of-the-linked-list/

// Solution 1
//Put every node into an vector v in order. 
//Then the middle node is just v[v.length // 2], 
//since we can retrieve each node by index.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       
        vector<ListNode*> v = {head} ;
        
        while(v.back()->next != NULL){
            v.push_back(v.back()->next);
        }
        return v[v.size() / 2]    ;
    }
};

//Complexity Analysis
//Time Complexity: O(N), where N is the number of nodes in the given list.
//Space Complexity: O(N), the space used by A.


// Solution 2

//Intuition and Algorithm
//When traversing the list with a pointer first,
//make another pointer second that traverses twice as second. 
//When second reaches the end of the list, 
//first must be in the middle.


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* first  = head;
        ListNode* second = head;
        
        while(second != NULL && second->next != NULL){
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};

//Complexity Analysis
//Time Complexity: O(N), where NN is the number of nodes in the given list.
//Space Complexity: O(1), the space used by slow and fast.




// APP 3

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = 0; 
        // Traverse temp till the end of linked list to find the length. 
        while(temp){
            temp = temp -> next;
            len++;
        }
        int middle = len/2;
        temp = head;
        
        while(middle--){
            temp = temp -> next;
        }
        
        return temp;
    }
};
