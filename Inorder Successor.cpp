1. 有父指针

2. 无父指针，但是BST
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

3. 无父指针
class Solution {
public:
	TreeNode *getNext(TreeNode* target, TreeNode *root) {
		
		TreeNode *prev = NULL;
		stk.push(root);
		pushLeftChild(root);
		while (!stk.empty()) {
			auto node = stk.top();
			if (prev && prev == target) {
				return node;
			}
			cout << node->val<<" ";
			prev = node;
			stk.pop();
			if (node->right) {
				stk.push(node->right);
				pushLeftChild(node->right);
			}
		}
		return NULL;
	}
private:
	stack<TreeNode*> stk;
	void pushLeftChild(TreeNode* root) {
		if (!root) {
			return;
		}
		while (root->left) {
			stk.push(root->left);
			root = root->left;
		}
	}
};

