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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        inorder(root, prev, ans);
        return ans;
    }

private:
    void inorder(TreeNode* node, int &prev, int &ans) {
        if (!node) return;

        inorder(node->left, prev, ans);

        if (prev != -1) {
            ans = min(ans, node->val - prev);
        }
        prev = node->val;

        inorder(node->right, prev, ans);
    }
};
