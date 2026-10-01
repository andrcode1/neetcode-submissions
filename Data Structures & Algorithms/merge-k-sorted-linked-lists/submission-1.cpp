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

/**
lists:
[1, 2, 4, 5]
[0, 0, 1, 3]
[0, 0, 1]

[0, 0, 0, 0, 1, 1, 1]

listPtrs:
[1]-
[0]-
[0]-
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode sentinel(0);
        ListNode* head = &sentinel;
        auto cmp = [](ListNode* first, ListNode* second) {
            return first->val > second->val;
        };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap;

        for (auto& list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            head->next = minNode;
            head = head->next;
            minHeap.pop();
            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        return sentinel.next;
    }
};
