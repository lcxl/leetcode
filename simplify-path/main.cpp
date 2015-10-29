#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> path_list;
		int i = 0;
		int prep = 0;
		path.push_back('/');
		for (i = 0; i < path.length(); i++) {
			if (path[i] == '/') {
				if (i > prep) {
					string sub_str = path.substr(prep, i - prep);
					if (sub_str == "..") {
						//上一级目录
						if (path_list.size() > 0) {
							//目录回退
							path_list.pop_back();
						}
					}
					else if (sub_str != "."){
						//如果不是当前目录
						path_list.push_back(sub_str);
					}
				}
				prep = i + 1;
			}
		}
		if (path_list.size() == 0) {
			return "/";
		}
		string resu;
		for (auto it = path_list.begin(); it != path_list.end(); it++) {
			resu.push_back('/');
			resu += *it;
		}
		return resu;
	}
};

int main()
{
	Solution solution = Solution();
	string path = solution.simplifyPath("/../../../..///1111");
	printf_s(path.c_str());
	return 0;
}