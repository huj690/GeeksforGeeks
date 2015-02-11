class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        TreeNode *prev = NULL;
        flattenHelper(root, prev);
    }
private:
    void flattenHelper(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) {
            return;
        }
        TreeNode* right = root->right;
        if (prev != NULL) {
            prev->right = root;
            prev->left = NULL;
        }
        prev = root;
        flattenHelper(root->left, prev);
        flattenHelper(right, prev);
    }
};
