#include<vector>
#include<cstdio>
#include<string>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//¶þ·Ö²éÕÒ
		int left = 0;
		int right = nums.size()-1;
		while (left <= right) {
			int mid = (right + left) / 2;
			
			int leftNumber = nums[left];
			int rightNumber = nums[right];
			int midNumber = nums[mid];
			if (midNumber > target) {
				if (leftNumber > target) {
					if (rightNumber < target) {
						return false;
					}
					else if (rightNumber == target) {
						return true;
					}else {
						left += 1;
						right -= 1;
					}
					
				}
				else {
					right = mid - 1;
				}
			}
			else if (midNumber < target) {
				
				if (rightNumber < target) {
					if (leftNumber > target) {
						return false;
					}
					else if (leftNumber == target) {
						return true;
					}
					else {
						left += 1;
						right -= 1;
					}
					
				}
				else {
					left = mid + 1;
				}
			}
			else {
				return true;
			}
		}
		return false;
	}
};


int main()
{
	vector<int> nums = vector<int>({5,6,8,9,10,0,2,3});
	Solution solution = Solution();
	int index;
	
	index = solution.search(nums, 4);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 1);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 11);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 7);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 10);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 6);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 3);
	printf_s("index=%d\n", index);

	index = solution.search(nums, 2);
	printf_s("index=%d\n", index);
	return 0;
}