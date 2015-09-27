#include<vector>
#include<cstdio>
#include<string>

using namespace std;

class Solution {
public:
	//还是二分查找
	vector<int> searchRange(vector<int>& nums, int target) {

		if (nums.size() == 0) {
			return vector<int>({ -1,-1 });
		}

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		bool isfound = false;
		while (left <= right) {
			mid = (left + right) / 2;
			int mid_value = nums[mid];

			if (mid_value > target) {
				right = mid - 1;
				
			}
			else if (mid_value < target){
				left = mid + 1;
			}
			else {
				isfound = true;
				break;
			}
		}
		//如果没有找到，退出
		if (!isfound) {
			return vector<int>({ -1,-1 });
		}
		//找到了，再按照left到right的范围进行二分查找
		int border;

		//先找左边的
		border = mid;
		while (left < border) {
			int new_mid = (left + border) / 2;
			int mid_value = nums[new_mid];
			if (mid_value == target) {
				border = new_mid;
			}
			else if (mid_value < target){
				left = new_mid + 1;
			}
		}
		//再找右边的
		border = mid;
		while (right > border) {
			//注意这里的+1
			int new_mid = (right + border) / 2 + 1;
			int mid_value = nums[new_mid];
			if (mid_value == target) {
				border = new_mid;
			}
			else if (mid_value > target) {
				right = new_mid - 1;
			}
		}
		return vector<int>({ left, right });
	}
};

int main()
{
	Solution solution = Solution();

	vector<int> resu = solution.searchRange(vector<int>({1}), 0);
	for (auto it = resu.begin(); it != resu.end(); it++) {
		printf_s("%d, ", (*it));
	}
	printf_s("\n");
	return 0;
}