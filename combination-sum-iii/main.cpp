#include<vector>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

class Solution {
private:
	vector<vector<int>> sum3(int begin, int k, int n) {
		vector<vector<int>> resu;
		if (k == 0) {
			return resu;
		}
		if (k == 1) {
			if (n < 10) {
				resu.push_back(vector<int>({ n }));
			}
			return resu;
		}
		//����(a+b)/2*c<2nʱ��c�����ֵ�Ƕ��٣��������Ǽ���һԪ���β���ʽ
		//����aΪi��bΪa+c-1
		//���c֮�󣬾������b�Ƕ�����
		int max = 0;
		for (int i = begin + 1; i <= (max = (int)((-1 + sqrt(pow(2 * i - 1, 2) + 8 * n)) / 2)); i++) {
			if (n - i <= i) {
				break;
			}
			vector<vector<int>> sub_resu = sum3(i, k - 1, n - i);
			for (auto it = sub_resu.begin(); it != sub_resu.end(); it++) {
				auto sit = (*it).begin();
				(*it).insert(sit, i);
				resu.push_back((*it));
			}
		}
		return resu;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		return sum3(0, k, n);
	}
};

int main()
{
	Solution solution = Solution();
	
	vector<vector<int>> resu = solution.combinationSum3(3, 9);
	for (auto it = resu.begin(); it != resu.end(); it++) {
		auto line = (*it);
		for (auto lineit = line.begin(); lineit != line.end(); lineit++) {
			printf_s("%d,", (*lineit));
		}
		printf_s("\n");
	}

	return 0;
}