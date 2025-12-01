// # Intuition
// -> First Thought is to reverse the half list and check if the it matches with the other half or not.

// # Approach
// -> Use fast and slow pointer approach to find the middle element of the list.
// -> Reverse the other half of the list.
// -> Bring fast to the head and slow to the new head.
// -> Check if the fast and slow elements match or not. 

// # Complexity
// - Time complexity:
// -> O(N)

// - Space complexity:
// -> O(1)

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

    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverse(slow->next);
        fast = head;
        slow = newhead;
        while(slow != NULL){
            if(fast->val != slow->val){
                reverse(newhead);
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
