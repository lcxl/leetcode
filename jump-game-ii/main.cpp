#include<vector>
#include<cstdio>
#include<string>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) {
			return 0;
		}
		//步数初始为1
		int step = 1;
		//当前所在位置
		int pos = 0;
		while (pos + 1 + nums[pos] < nums.size()) {
			int maxpos = 0;
			int nextpos = 0;
			for (int i = 1; i <= nums[pos]; i++) {
				//计算nums[pos + i]这个点所能到达的最大位置
				int topos = pos + i + nums[pos + i];
				if (topos > maxpos) {
					maxpos = topos;
					nextpos = pos + i;
				}
			}
			pos = nextpos;
			step++;
		}
		return step;
	}
};

int main()
{
	Solution solution = Solution();

	vector<int> nums = vector<int>({2,3,1,1,4});
	int step = solution.jump(nums);
	printf_s("step=%d\n", step);

	nums = vector<int>({ 4,3,1,1,4 });
	step = solution.jump(nums);
	printf_s("step=%d\n", step);

	return 0;
}