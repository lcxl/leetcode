#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//num1����ĵ�ǰ���
		int nums1_index = m - 1;
		//num2����ĵ�ǰ���
		int nums2_index = n - 1;
		//��num1��num2��ĩβ�Ƚ�
		//ֱ��nums2_indexС��0��num2�����꣩Ϊֹ
		while (nums2_index >= 0) {
			int value2 = nums2[nums2_index];
			//���nums1�Ѿ��������ˣ��Ǿ�ֻ��nums2��Ԭ��
			if (nums1_index < 0) {
				nums1[nums1_index + nums2_index + 1] = value2;
				nums2_index--;
			}
			else {
				//��û�б����꣬�Ƚ�����Ԫ�صĴ�С
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