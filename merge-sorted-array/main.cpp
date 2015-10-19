#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//num1数组的当前序号
		int nums1_index = m - 1;
		//num2数组的当前序号
		int nums2_index = n - 1;
		//从num1和num2的末尾比较
		//直到nums2_index小于0（num2遍历完）为止
		while (nums2_index >= 0) {
			int value2 = nums2[nums2_index];
			//如果nums1已经遍历完了，那就只用nums2的袁术
			if (nums1_index < 0) {
				nums1[nums1_index + nums2_index + 1] = value2;
				nums2_index--;
			}
			else {
				//都没有遍历完，比较两个元素的大小
				int value1 = nums1[nums1_index];
				if (value1 > value2) {
					nums1[nums1_index + nums2_index + 1] = value1;
					nums1_index--;
				}
				else {
					nums1[nums1_index + nums2_index + 1] = value2;
					nums2_index--;
				}
			}
		}
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums1 = vector<int>({1,2,3,4,5,6,7,8});
	return 0;
}