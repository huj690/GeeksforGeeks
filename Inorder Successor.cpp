1. 有父指针


2. 无父指针，但是是BST
class Solution {
public:
	TreeNode *getNext(TreeNode* node, TreeNode *root) {
		if (!node || !root) {
			return NULL;
		}
		if (node->right) {
			return getLeftMost(node->right);
		}
		TreeNode* succ = NULL;
		while (root) {
			if (node->val > root->val) {
				succ = root;
				root = root->right;
			} else if (node->val < root->val) { 
				succ = root;
				root = root->left;
			} else {
				break;
			}
		}
		return succ;

	}
private:
	TreeNode* getLeftMost(TreeNode* node) {
		if (!node) {
			return NULL;
		}
		while (node->left) {
			node = node->left;
		}
		return node;
	}
};
