// # Intuition
// Fast and Slow pointer technique.

// # Approach
// -> Create two pointers fast and slow.
// -> Move fast by 2 steps and slow by 1 till fast is valid.
// -> If the fast and slow pointers meet then there is a cycle in the list.
// -> Now move slow to the head and move both pointers by 1.
// -> When the pointers meet again that is the starting of the cycle.

// # Complexity
// - Time complexity:
// O(N)

// - Space complexity:
// O(1)

// # Code
// ```cpp []

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
