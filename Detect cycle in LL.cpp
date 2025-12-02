// # Intuition
// -> Use fast and slow pointers.

// # Approach
// -> Create 2 pointers fast and slow.
// -> Move fast pointer by 2 steps and slow by 1 step.
// -> If both the pointers meet that means List has a cycle then return true.
// -> Else return false.

// # Complexity
// - Time complexity:
// O(N)

// - Space complexity:
// O(1)

// # Code
// cpp []

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
