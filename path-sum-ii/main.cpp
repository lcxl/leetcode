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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> resu;

		if (!root) {
			return resu;
		}

		int nextsum = sum - root->val;

		if (root->left) {
			vector<vector<int>> left = pathSum(root->left, nextsum);
			for (auto it = left.begin(); it != left.end(); it++) {
				(*it).insert((*it).begin(), root->val);
				resu.push_back((*it));
			}
		}

		if (root->right) {
			vector<vector<int>> right = pathSum(root->right, nextsum);
			for (auto it = right.begin(); it != right.end(); it++) {
				(*it).insert((*it).begin(), root->val);
				resu.push_back((*it));
			}
		}

		if (!root->left && !root->right) {
			if (nextsum == 0) {
				vector<int> buttom = vector<int>{ root->val };
				resu.push_back(buttom);
			}
		}
		return resu;
	}
};

int main()
{
	Solution solution = Solution();

	return 0;
}