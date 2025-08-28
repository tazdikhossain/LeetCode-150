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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to start before and after lists
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);

        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        // Traverse original list
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        // Connect before list with after list
        after->next = nullptr;       // important: avoid cycle
        before->next = afterHead->next;

        return beforeHead->next;
    }
};
