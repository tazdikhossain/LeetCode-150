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
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // second is before the node to delete
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete; // free memory

        return dummy->next;
    }
};
