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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // 1. Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // 'curr' will be the start of sublist to reverse
        ListNode* curr = prev->next;

        // 2. Reverse from left to right
        // standard reversal but only (right-left) steps
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;     // node to move
            curr->next = temp->next;         // unlink temp
            temp->next = prev->next;         // insert temp at front
            prev->next = temp;               // move prev forward
        }

        return dummy.next;
    }
};
