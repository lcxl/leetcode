#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
private:
	struct TreeNodeEx : public TreeNode {
		//子节点的最大值
		int max_chind_path_val;
		TreeNodeEx(int x) : TreeNode(x), max_chind_path_val(0) {}
	};
private:
	TreeNodeEx* buildTreeEx(TreeNode* root) {
		TreeNodeEx* resu = new TreeNodeEx(root->val);
		int left_max_chind_path_val = 0;
		if (root->left) {
			resu->left = buildTreeEx(root->left);
			left_max_chind_path_val = ((TreeNodeEx*)resu->left)->max_chind_path_val + resu->left->val;
			if (left_max_chind_path_val < 0) {
				left_max_chind_path_val = 0;
			}
		}
		int right_max_chind_path_val = 0;
		if (root->right) {
			resu->right = buildTreeEx(root->right);
			right_max_chind_path_val = ((TreeNodeEx*)resu->right)->max_chind_path_val + resu->right->val;
			if (right_max_chind_path_val < 0) {
				right_max_chind_path_val = 0;
			}
		}
		//最大值
		resu->max_chind_path_val = left_max_chind_path_val > right_max_chind_path_val ? left_max_chind_path_val : right_max_chind_path_val;
		return resu;
	}
private:
	int max_value = INT32_MIN;
	void maxPathSum(TreeNodeEx* root) {
		int _max_value = root->val;
		if (root->left) {
			maxPathSum((TreeNodeEx*)root->left);
			int tmp = ((TreeNodeEx*)root->left)->max_chind_path_val + root->left->val;
			if (tmp > 0) {
				_max_value += tmp;
			}
			
		}
		if (root->right) {
			maxPathSum((TreeNodeEx*)root->right);
			int tmp = ((TreeNodeEx*)root->right)->max_chind_path_val + root->right->val;
			if (tmp > 0) {
				_max_value += tmp;
			}
		}
		if (_max_value > this->max_value) {
			this->max_value = _max_value;
		}
	}
public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr) {
			return this->max_value;
		}
		TreeNodeEx* rootEx = buildTreeEx(root);
		maxPathSum(rootEx);
		return this->max_value;
	}
};

int main()
{
	Solution solution = Solution();
	/*
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(100);
	root->left->right = new TreeNode(100);
	*/
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(-1);
	int max_value = solution.maxPathSum(root);
	printf("%d\n", max_value);
	return 0;
}