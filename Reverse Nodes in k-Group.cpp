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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Check if we have k nodes
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head;  // fewer than k, no reverse
            node = node->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Recursively process rest and connect
        head->next = reverseKGroup(curr, k);

        return prev;  // new head of this block
    }
};
