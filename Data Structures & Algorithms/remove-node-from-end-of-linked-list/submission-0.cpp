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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode sentinel(0);
        sentinel.next = head;

        ListNode* prevSlow = &sentinel;
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 1; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
            prevSlow = prevSlow->next;
        }
        prevSlow->next = slow->next;

        return sentinel.next;
    }
};
