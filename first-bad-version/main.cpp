#include<vector>
#include<cstdio>
#include<string>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	//二分查找，注意有符号的int会出错
	int firstBadVersion(int n) {
		unsigned int left = 1;
		unsigned int right = n;
		
		while (left < right) {
			unsigned int mid = (left + right) / 2;
			bool resu = isBadVersion(mid);

			if (resu) {
				right = mid;
			}
			else {
				left = mid+1;
			}
		}
		return (int)left;
	}
};

bool isBadVersion(int version) {
	return version >= 1702766719;
}

int main()
{
	Solution solution = Solution();
	int resu = solution.firstBadVersion(2126753390);
	printf_s("first bad version is %d", resu);
	return 0;
}