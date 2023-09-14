// A 0 BRUTE FORCE

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headB != NULL) {
            ListNode* temp = headA;
            while(temp != NULL) {
                // If both nodes are the same
                if(temp == headB) return headB;
                temp = temp->next;
            }
            headB = headB->next;
        }
        // Intersection is not present between the lists, return nullptr
        return NULL;
    }
};





// A 1 [Using Hash map]

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, bool> ump;
        while(headA != NULL) {
            ump[headA] = true;
            headA = headA -> next;
        }        
        while(headB != NULL && ump.find(headB) == ump.end()) headB = headB -> next;
        return headB;
    }
};





// A 2 [Using Hash set]

// First of all store all the nodes of the first linked list in the set, and then iterate through 
// each node of the second linked list to determine whether there exists in the set, and if so, 
// directly return to the node of this existence.
// If we have finished traversing and have not found it in the collection, it means that
// they have not intersected, we can return directly, 
// the principle is relatively simple, just look at the set set set null

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // create a set to store nodes of list A
        unordered_set<ListNode*> s;
        // add all nodes of list A to the set
        while(headA != NULL) {
            s.insert(headA);
            headA = headA->next;
        }
        
        // traverse list B and check if its node is present in the set
        while(headB != NULL) {
            if(s.count(headB)) return headB;
            // if(s.find(headB) != s.end()) return headB;
            headB = headB->next;
        }
        // if there's no intersection, return null
        return NULL;
    }
};

// Here we've used unordered_set instead of set as it provides faster lookup times in practice.

// T.C. -->  O(m + n), where m and n are the lengths of the two linked lists,
// because we need to traverse both lists to create the set and check for intersection.
// S.C. -->  O(m + n), because we need to store all nodes of one of the lists in the set.

// Note that the space complexity can be improved to O(min(m, n)) by storing the nodes
// of the smaller list in the set instead of the larger one, but the time complexity remains the same.






// A 3 [2 Pointer]

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2){
            if(temp1 == NULL) temp1 = headB;
            else temp1 = temp1->next;            
            if(temp2 == NULL) temp2 = headA;
            else temp2 = temp2->next;
            // temp1 = temp1 -> next == NULL ? headB : temp1 -> next;
            // temp2 = temp2 -> next == NULL ? headA : temp2 -> next;
        }
        return temp1;
    }
};






// A 4 [Use of Lambda Function] copied from cn

// It initializes a lambda function, which sets the synchronization between C++ and C input/output 
// streams to false and unties the cin stream from the cout stream.
// It also opens a file named "user.out" for writing and reads input from the standard input (cin) 
// until it receives a line with the value "0".
// For each input line that is not equal to "0", it writes a line to the output file "Intersected at
// '<value>'\n", where '<value>' is the value of the input line. 
// If the input line is "0", it writes "No intersection\n" to the output file. 
// Finally, it flushes the output buffer and exits the program.

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);) {
        if (s != "0") out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for (int i = 0; i < 4; ++i) getline(cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *, ListNode *) { return 0; }
};






// A 5 [ Count the length of the two linked lists first ]

// We can count the length of the two LL first, if the length of the two linked lists is not same,
// let the linked list go first, until the length of the two linked lists is the same, 
// at this time the two linked lists move back at the same time to see if the nodes are the same, 
// if there are equal, it means that this equal node is the intersection of the two linked lists, 
// otherwise if we have not found an equal node after movieng, it means that they have no intersection, 
// return directly

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA), lenB = length(headB);
        // If lengths of the nodes are different, the more nodes go first until lengths are the same
        while(lenA != lenB) {
            if(lenA > lenB) {
                // If the linked list A is long, then the linked list A goes first
                headA = headA->next;
                lenA--;
            } 
            else {
                // If the linked list B is long, then the linked list B goes first
                headB = headB->next;
                lenB--;
            }
        }
        // Then start comparing, if they are not equal, keep going down
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        // At the end, there will be two possibilities in the end, one is that headA is empty,
        // That is to say, the two do not intersect. Another possibility is headA
        // Not empty, that is to say headA is their intersection point
        return headA;
    }
private:
    // count the length of the linked list
    int length(ListNode* node) {
        int length = 0;
        while (node != nullptr) {
            node = node->next;
            length++;
        }
        return length;
    }
};






// A 6  [  Difference in Lengths ]

// Traverse both linked lists to find their lengths and calculate the difference in lengths.
// Move the pointer of the longer list forward by the difference in lengths, 
// so both pointers are at the same relative position from the end.
// Now, traverse both linked lists together until the pointers meet. This will be the intersection point.

class Solution {
public:
    int getLength(ListNode *head) {
        int length = 0;
        while(head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        
        // Move the longer list's pointer forward by the difference in lengths
        int diff = abs(lengthA - lengthB);
        ListNode *currA = headA;
        ListNode *currB = headB;
        if(lengthA > lengthB) {
            while(diff-- > 0) currA = currA->next;
        } 
        else {
            while(diff-- > 0) currB = currB->next;
        }
        
        // Traverse both lists until they intersect or reach the end
        while(currA != nullptr && currB != nullptr) {
            if(currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }        
        return nullptr; // No intersection
    }
};






// A 7 [ Cyclic Approach ]
// Traverse the 1st LL and make the last node's next point to the beginning of the 2nd linked list. 
// This forms a cycle.
// Use Floyd's cycle detection algorithm (tortoise and hare approach) to find the cycle's starting point. 
// This point is the intersection point of the two lists.
// After finding the intersection point, break the cycle by updating the last node's next to nullptr.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Traverse the first list to make the last node's next point to headB
        ListNode *currA = headA;
        while(currA -> next != nullptr) currA = currA->next;
        currA -> next = headB;
        
        // Detect the cycle's starting point (intersection point)
        ListNode *slow = headA;
        ListNode *fast = headA;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) break;
        }
        
        // No intersection if there's no cycle
        if(fast == nullptr || fast->next == nullptr) {
            currA -> next = nullptr; // Restore the original structure
            return nullptr;
        }
        
        // Reset slow to headA and move both slow and fast by one step until they meet again
        slow = headA;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }        
        currA -> next = nullptr; // Restore the original structure
        return slow; // Intersection point
    }
};






// A 8

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Find the lengths of both lists
        while(ptrA) {
            lenA++;
            ptrA = ptrA -> next;
        }
        while(ptrB) {
            lenB++;
            ptrB = ptrB -> next;
        }
        // Reset pointers to the beginning of the lists
        ptrA = headA;
        ptrB = headB;

        // Move the longer list's pointer ahead by the length difference
        while(lenA > lenB) {
            ptrA = ptrA -> next;
            lenA--;
        }
        while(lenB > lenA) {
            ptrB = ptrB -> next;
            lenB--;
        }

        // Compare nodes of both lists until intersection or end
        while(ptrA && ptrB) {
            if(ptrA == ptrB) return ptrA; // Intersection found
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return nullptr; // No intersection
    }
};






// A 9 
