// # Intuition
// Use recursion if child is found.

// # Approach
// -> Make a curr pointer which points to head.
// -> Run a while loop till curr points to NULL.
// -> if curr points to the element who have a child then create a next pointer which points to next of curr.
// -> Call the function for curr's child has the next element of the node.
// -> Since the list is double linked list then point the curr's next previous i.e. to curr.
// -> And curr's child to NULL because now it has no child and all the child element has moved to the next of curr.
// -> Move curr till curr next is not valid. Means curr will point to end node of the child.
// -> Now the next pointer is pointing to curr's next which was at start.
// -> If that next pointer if not null then connect curr to next as doubly linked list.
// -> return head.

// # Complexity
// - Time complexity:
// O(N)

// - Space complexity:
// O(1)

// # Code
// cpp []
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }
        Node* curr = head;
        while (curr != NULL) {
            if (curr->child) {
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                while (curr->next) {
                    curr = curr->next;
                }
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
