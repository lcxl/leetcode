#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
	/*
	����ķ���ֵ��combinationSum�ķ���ֵ�ĺ��岻һ����
	���緵��ֵ����һ�����Ϊ[1,2],�������������candidates�������Ϊindex��index+1��Ԫ������Ϊ1��2
	*/
	vector<vector<int>> combinationSum(vector<int>& candidates, int index, int target) {
		vector<vector<int>> resu;
		
		int n = target / candidates[index];
		//���nΪ0�Ļ���˵��target���Ѿ���candidates[index]ҪС���Ͳ���Ҫ���������ж���
		if (n == 0) {
			return resu;
		}
		//����������������������
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
		//������
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) {
			return resu;
		}
		vector<vector<int>> resu2 = combinationSum(candidates, 0, target);
		for (auto it2 = resu2.begin(); it2 != resu2.end(); it2++) {
			auto sub_resu2 = *it2;
			vector<int> sub_resu;
			for (int sub_i2 = 0; sub_i2 < (int)sub_resu2.size(); sub_i2++) {
				//Ԫ��ֵ
				auto element_value = candidates[sub_i2];
				//Ԫ������
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