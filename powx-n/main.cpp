#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	//两倍两倍的进行计算
	double myPow(double x, int n) {
		double resu = 1;
		int mn = 1;
		double mx = x;
		//判断n是否为负数
		bool is_negative = n < 0;
		if (is_negative) {
			n = -n;
		}
		while (n > 0) {
			resu *= mx;
			if ((mn << 1) <= n-mn) {
				mn = mn << 1;
				mx *= mx;
			} else{
				mn = 1;
				mx = x;
			}
			n -= mn;
		}
		if (is_negative) {
			resu = 1 / resu;
		}
		return resu;
	}
};

int main()
{
	Solution solution = Solution();
	double resu  = solution.myPow(2, -3);
	printf_s("%f\n%f\n", resu, pow(2, -3));
	return 0;
}