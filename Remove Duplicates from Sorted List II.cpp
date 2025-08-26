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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while (prev->next) {
            ListNode* curr = prev->next;
            bool dup = false;
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
                dup = true;
            }
            if (dup) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
