// unique-binary-search-trees-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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
	vector<TreeNode*> createTrees(int currIndex, int firstIndex, int lastIndex) {
		vector<TreeNode*> leftList;
		for (int i = firstIndex; i < currIndex; i++) {
			vector<TreeNode*> left = createTrees(i, firstIndex, currIndex-1);
			leftList.insert(leftList.end(), left.begin(), left.end());
		}
		vector<TreeNode*> rightList;
		for (int i = currIndex +1; i <= lastIndex; i++) {
			vector<TreeNode*>  right= createTrees(i, currIndex + 1, lastIndex);
			rightList.insert(rightList.end(), right.begin(), right.end());
		}

		vector<TreeNode*> toalList;
		if (!leftList.empty()) {
			if (!rightList.empty()) {
				for (auto i = leftList.begin(); i != leftList.end(); i++) {
					for (auto j = rightList.begin(); j != rightList.end(); j++) {
						TreeNode *pparentNode = new TreeNode(currIndex);
						pparentNode->left = (*i);
						pparentNode->right = (*j);
						toalList.push_back(pparentNode);
					}
				}
			}
			else {
				for (auto i = leftList.begin(); i != leftList.end(); i++) {
						TreeNode *pparentNode = new TreeNode(currIndex);
						pparentNode->left = (*i);
						pparentNode->right = nullptr;
						toalList.push_back(pparentNode);
					}
				
			}
		}
		else {
			if (!rightList.empty()) {
				for (auto j = rightList.begin(); j != rightList.end(); j++) {
					TreeNode *pparentNode = new TreeNode(currIndex);
					pparentNode->left = nullptr;
					pparentNode->right = (*j);
					toalList.push_back(pparentNode);
				}
			}
			else {
				TreeNode *pparentNode = new TreeNode(currIndex);
				pparentNode->left = nullptr;
				pparentNode->right = nullptr;
				toalList.push_back(pparentNode);
			}
		}
		return toalList;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> treeList = vector<TreeNode*>();

		for (int i = 1; i <= n; i++) {
			
			vector<TreeNode*> list = createTrees(i, 1, n);
			treeList.insert(treeList.end(), list.begin(), list.end());
		}
		if (treeList.empty()) {
			treeList.push_back(nullptr);
		}
		return treeList;
	}
};

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	Solution solution = Solution();

	solution.generateTrees(n);

    return 0;
}

