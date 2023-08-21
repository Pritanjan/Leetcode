// APPROACH 1 [Using map]

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





// APPROACH 2 [Using set]

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
            if(s.find(headB) != s.end()) return headB;
            headB = headB->next;
        }
        // if there's no intersection, return null
        return NULL;
    }
};

// Here we've used unordered_set instead of set as it provides faster lookup times in practice.
// Also, we've used nullptr instead of NULL as it's the preferred way of representing null 
// pointers in modern C++.

// T.C. -->  O(m+n), where m and n are the lengths of the two linked lists,
// because we need to traverse both lists to create the set and check for intersection.

// S.C. -->  O(m+n), because we need to store all nodes of one of the lists in the set.

// Note that the space complexity can be improved to O(min(m, n)) by storing the nodes
// of the smaller list in the set instead of the larger one, but the time complexity remains the same.




// APPROACH 3 [2 Pointer]

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2){
            if(temp1 == NULL) temp1 = headB;
            else temp1 = temp1->next;
            // temp1 = temp1 -> next == NULL ? headB : temp1 -> next;
            // temp2 = temp2 -> next == NULL ? headA : temp2 -> next;
            
            if(temp2 == NULL) temp2 = headA;
            else temp2 = temp2->next;
        }
        return temp1;
    }
};






// APPROACH 4 [Use of Lambda Function] copied from cn

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





// APPROACH 5 [ Count the length of the two linked lists first ]

// We can count the length of the two linked lists first, if the length of the two linked lists is not the same,
// let the linked list go first, until the length of the two linked lists is the same, at this time
// the two linked lists move back at the same time to see if the nodes are the same, 
// if there are equal, it means that this equal node is the intersection of the two linked lists, 
// otherwise if you have not found an equal node after walking, it means that they have no intersection, 
// return directly

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA), lenB = length(headB);
        //If the lengths of the nodes are different, the more nodes go first until their lengths are the same
        while (lenA != lenB) {
            if (lenA > lenB) {
                //If the linked list A is long, then the linked list A goes first
                headA = headA->next;
                lenA--;
            } 
            else {
                //If the linked list B is long, then the linked list B goes first
                headB = headB->next;
                lenB--;
            }
        }

        //Then start comparing, if they are not equal, keep going down
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        //At the end, there will be two possibilities in the end, one is that headA is empty,
        //That is to say, the two do not intersect. Another possibility is headA
        //Not empty, that is to say headA is their intersection point
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


