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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
        }

        ListNode* prevNode = nullptr;
        ListNode* currNode = slow;
        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next;

            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        ListNode* left = head;
        ListNode* right = prevNode;
        while (right->next != nullptr) {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }
    }
};
