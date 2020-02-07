/*计算a+b区分是否大于0，小于0取绝对值，将结果tostring存入第一个字符串内，倒序push back 进新字符串，每三位加一个逗号
，如果输出到原字符串头部刚好三位不加逗号
对小于零的情况最后push back一个-号
最后对新字符串倒序输出
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long a, b, sum;
	scanf("%lld%lld", &a, &b);
	sum = a + b;
	string sum_s;
	string sum_ans;
	if (sum < 0) {
		sum_s = to_string(abs(sum));

		
		for (int i = 0; i < sum_s.size(); i++) {
			if ((i + 1) % 3 == 0 && i != sum_s.size() - 1) { sum_ans.push_back(sum_s[sum_s.size() - i - 1]);
			sum_ans.push_back(',');
			}
			else {
				sum_ans.push_back(sum_s[sum_s.size() - i - 1]);
			}

			
		}
		sum_ans.push_back('-');
	}
	else {
		sum_s = to_string(sum);
		for (int i = 0; i < sum_s.size(); i++) {
			if ((i + 1) % 3 == 0 && i != sum_s.size() - 1) {
				sum_ans.push_back(sum_s[sum_s.size() - i - 1]);
				sum_ans.push_back(',');
			}
			else {
				sum_ans.push_back(sum_s[sum_s.size() - i - 1]);
			}
		}
	}
	for (int i = sum_ans.size() - 1; i >= 0; i--)
		cout << sum_ans[i];
	return 0;
}