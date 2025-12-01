// # Intuition
// -> Use fast and slow pointers. 

// # Approach
// -> Move slow pointer by one step and fast pointer by 2 steps.
// -> Move untill fast reaches to the end element of the list.
// -> When the fast points to last element, the slow will point to middle element of the list

// # Complexity
// - Time complexity:
// O(1)

// - Space complexity:
// O(1)

// # Code
// cpp 
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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
    }
    return slow;
    }
};
