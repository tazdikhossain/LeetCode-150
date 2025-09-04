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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, inorderMap, postIndex, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int,int>& inorderMap,
                    int& postIndex, int left, int right) {
        if (left > right) return nullptr;
        
        // Root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        // Inorder index of root
        int idx = inorderMap[rootVal];
        
        // Build right first, then left (because postorder goes root->right->left backwards)
        root->right = build(inorder, postorder, inorderMap, postIndex, idx + 1, right);
        root->left = build(inorder, postorder, inorderMap, postIndex, left, idx - 1);
        
        return root;
    }
};
