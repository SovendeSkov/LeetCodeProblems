// # Problem
// You are given the heads of two sorted linked lists `list1` and `list2`.
// Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.
// Return _the head of the merged linked list_.

// **Example 1:**
// ![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

// **Input:** list1 = `[1,2,4]`, list2 = `[1,3,4]`
// **Output:** `[1,1,2,3,4,4]`

// **Example 2:**

// **Input:** list1 = [], list2 = []
// **Output:** []

// **Example 3:**

// **Input:** list1 = [], list2 = `[0]`
// **Output:** `[0]`

// **Constraints:**

// - The number of nodes in both lists is in the range `[0, 50]`.
// - `-100 <= Node.val <= 100`
// - Both `list1` and `list2` are sorted in **non-decreasing** order.

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

        if(list1==NULL) {
            return list2;
        }
        
        if(list2==NULL) {
            return list1;
        }

        ListNode* tempHead = new ListNode();
        ListNode* tail = tempHead;

        while (list1 != nullptr || list2 != nullptr) {

            // Fetch the val information
            int val1 = (list1 != nullptr) ? list1->val : 101;
            int val2 = (list2 != nullptr) ? list2->val : 102;
            int lowerVal = 0;

            if (val1 <= 100 && val2 <= 100) {
                if (val1 < val2) {
                    lowerVal = val1;
                } else {
                    lowerVal = val2;
                }
            } else {
                if (val1 == 101) {
                    lowerVal = val2;
                }
                if (val2 == 102) {
                    lowerVal = val1;
                }
            }

            // Add to answer
            ListNode* newNode = new ListNode(lowerVal);
            tail->next = newNode;
            tail = tail->next;

            // Increment the list for the next count
            if (lowerVal == val1){
                list1 = (list1 != nullptr) ? list1->next : nullptr;
            } else {
                list2 = (list2 != nullptr) ? list2->next : nullptr;
            }
        }
        
        return tempHead->next;
    }
};
