#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
	/*
	递归调用
	*/
	vector<vector<int>> combinationSum2(vector<int>& candidates, int index, int target) {
		vector<vector<int>> resu;
		if (index >= candidates.size()) {
			return resu;
		}
		int value = candidates[index];
		if (target == value) {
			resu.push_back(vector<int>({ value }));
			return resu;
		}
		index++;
		if (index >= candidates.size()) {
			return resu;
		}
		if (value < target) {
			vector<vector<int>> sub_resu = combinationSum2(candidates, index, target - value);
			for (auto sub_it = sub_resu.begin(); sub_it != sub_resu.end(); sub_it++) {
				vector<int> &sub_line = (*sub_it);
				sub_line.insert(sub_line.begin(), value);
				resu.push_back(sub_line);
			}
		}
		//找下一个和index-1的值不一样的元素
		while (index < candidates.size()) {
			if (candidates[index] != candidates[index - 1]) {
				vector<vector<int>> sub_resu = combinationSum2(candidates, index, target);
				resu.insert(resu.end(), sub_resu.begin(), sub_resu.end());
				break;
			}
			index++;
		}
		
		return resu;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//先排序
		sort(candidates.begin(), candidates.end());
		return combinationSum2(candidates, 0, target);
	}
};

int main()
{
	Solution solution = Solution();

	vector<int> candidates = vector<int>({ 1,2,7,1,7,8,9 });
	vector<vector<int>> resu = solution.combinationSum2(candidates, 9);
	for (auto it = resu.begin(); it != resu.end(); it++) {
		auto line = (*it);
		for (auto lineit = line.begin(); lineit != line.end(); lineit++) {
			printf_s("%d,", (*lineit));
		}
		printf_s("\n");
	}

	return 0;
}