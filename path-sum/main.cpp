#include<vector>
#include<cstdio>
#include<string>

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
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) {
			return false;
		}
		int nextsum = sum - root->val;
		if (root->left) {
			if (hasPathSum(root->left, nextsum)) {
				return true;
			}
		}
		if (root->right) {
			if (hasPathSum(root->right, nextsum)) {
				return true;
			}
		}
		if (!root->left && !root->right) {
			return nextsum == 0;
		}
		return false;
	}
};

int main()
{
	Solution solution = Solution();

	return 0;
}