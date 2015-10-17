#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
	/*
	这里的返回值和combinationSum的返回值的含义不一样，
	例如返回值中有一个结果为[1,2],代表符合条件的candidates数组序号为index和index+1的元素数量为1和2
	*/
	vector<vector<int>> combinationSum(vector<int>& candidates, int index, int target) {
		vector<vector<int>> resu;
		
		int n = target / candidates[index];
		//如果n为0的话，说明target数已经比candidates[index]要小，就不需要做后续的判断了
		if (n == 0) {
			return resu;
		}
		//如果能整除，那添加这个结果
		if (target % candidates[index] == 0) {
			resu.push_back(vector<int>({ n }));
		}
		if (index < (int)candidates.size() - 1) {
			for (int i = n - 1; i >= 0; i--) {
				vector<vector<int>> sub_resu = combinationSum(candidates, index + 1, target - candidates[index] * i);
				for (auto sub_it = sub_resu.begin(); sub_it != sub_resu.end(); sub_it++) {
					
					(*sub_it).insert((*sub_it).begin(), i);
					resu.push_back(*sub_it);
				}
			}
		}
		return resu;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> resu;
		//先排序
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) {
			return resu;
		}
		vector<vector<int>> resu2 = combinationSum(candidates, 0, target);
		for (auto it2 = resu2.begin(); it2 != resu2.end(); it2++) {
			auto sub_resu2 = *it2;
			vector<int> sub_resu;
			for (int sub_i2 = 0; sub_i2 < (int)sub_resu2.size(); sub_i2++) {
				//元素值
				auto element_value = candidates[sub_i2];
				//元素数量
				auto element_number = sub_resu2[sub_i2];
				for (int j = 0; j < element_number; j++) {
					sub_resu.push_back(element_value);
					
				}
			}
			if (sub_resu.size() > 0) {
				resu.push_back(sub_resu);
			}
		}
		return resu;
	}
	
};

int main()
{
	Solution solution = Solution();

	vector<int> candidates = vector<int>({1,2});
	vector<vector<int>> resu = solution.combinationSum(candidates, 9);
	for (auto it = resu.begin(); it != resu.end(); it++) {
		auto line = (*it);
		for (auto lineit = line.begin(); lineit != line.end(); lineit++) {
			printf_s("%d,", (*lineit));
		}
		printf_s("\n");
	}

	return 0;
}