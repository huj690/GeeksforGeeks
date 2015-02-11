class Solution {
public:
    void convertBSTtoDLink(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        TreeNode* prev = NULL;
        convert(root, prev);
    }
private:
    void convert(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) {
            return;
        }
        convert(root->left, prev);
       
        root->left = prev;
        if (prev) {
            prev->right = root;
        }
        prev = root;
        convert(root->right, prev);
    }
};
