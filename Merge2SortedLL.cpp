// # Intuition
// -> Use recursion on the basis of which element is greater 

// # Approach
// -> if any of the list is NULL return the other list.
// -> if first element is smaller then call the same function starting with next element of the first list and same element of the second list.
// -> and if second element is smaller call from next element of the second list and same for first.
// -> If list1 have first smallest element then return list1.
// -> Else return list2.

// # Complexity
// - Time complexity:
// O(1)

// - Space complexity:
// O(1)

// # Code
// ```cpp []
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL || list2 == NULL){
            return list1 == NULL ? list2:list1;
        }
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
