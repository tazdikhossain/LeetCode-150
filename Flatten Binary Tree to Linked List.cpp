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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                // Attach original right subtree
                pre->right = curr->right;
                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node
            curr = curr->right;
        }
    }
};
