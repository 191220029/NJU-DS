/*
题目描述
我们考虑最简单的一种文本压缩方法：对于由相同的字符组成的一个连续的片段，用这个字符和片段中该字符的个数来表示。
例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。
本题需要你根据压缩的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由小写英文字母组成的非空字符串。

输入格式
输入第一行给出需要被压缩或解压的不超过 1000 个字符的字符串。
输出格式
在一行中输出压缩后的字符串。
样例 1
输入：
bccccccddd
输出：
b6c3d
样例 2
输入：
cccbbbcbbddcbccdcdcc
输出：
3c3bc2b2dcb2cdcd2c

*/

/*
#include<iostream>
#include<string.h>
using namespace std;


void solution_1() {
	string s; cin >> s;
	string res = "";

	int cnt = 0; char t;
for (int i = 0; i < s.length(); i++) {
	if (res.length() == 0) res = res + s[i];
	else {
		if (s[i] == res[res.length() - 1]) {
			cnt++;
		}
		else {
			if (cnt) {
				char c = res[res.length() - 1];
				cnt++;
				int j = 0;
				while (cnt) {
					if (j == 0) {
						res[res.length() - 1] = (char)((cnt % 10) + '0');
						j++;
					}
					else res = res + (char)((cnt % 10) + '0');
					cnt /= 10;
				}
				//res[res.length() - 1] = (char)(cnt + 1 + '0');
				res = res + c;
				cnt = 0;
			}
			res = res + s[i];
		}
	}
}


//对字符串末尾的处理
if (cnt) {
	char c = res[res.length() - 1];
	res[res.length() - 1] = (char)(cnt + 1 + '0');
	res = res + c;
	cnt = 0;
}

cout << res << endl;
}

int main() {
	solution_1();
	return 0;
}
*/