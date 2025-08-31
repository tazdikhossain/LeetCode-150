/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both null → same
        if (!p && !q) return true;

        // Case 2: one null, one not → different
        if (!p || !q) return false;

        // Case 3: values differ → different
        if (p->val != q->val) return false;

        // Case 4: check both subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
