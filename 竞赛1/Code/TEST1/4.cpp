/*
题目描述

小蓝鲸们已经排成了一排，每个小蓝鲸手上拿着一个小写英文字母，组成了一个字符串 s 。请你去掉这个字符串中拿着重复字母的小蓝鲸，使得s中所有不同的字母出现且只出现一次。并且，要使得返回结果的字符串的字典序最小（要求不能打乱小蓝鲸们的相对位置哟）。

输入格式

一行字符串s

输出格式

字典序最小的结果字符串

样例数据

样例1

输入
abae

输出
abe

样例2

输入
ecbaadaccc

输出
ebadc

数据规模

1<=len(s)<=5000000
1<=len(s)<=5000000

*/

/*
#include<iostream>
#include<string.h>
using namespace std;

int cnt[26] = { 0 };
int vflag[26] = { 0 };//是否访问过

void solution_4() {
	string s; cin >> s;
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']++;
	}//统计各字母出现次数
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']--;
		if (vflag[s[i] - 'a'])continue;//如果已经访问过该位置的字符则继续
		while (res.length() && cnt[res.back() - 'a'] > 0 && res.back() > s[i]) {
			vflag[res.back() - 'a'] = 0;
			res.pop_back(); //删去该字符
		}
		res += s[i];
		vflag[s[i] - 'a'] = 1;
	}
	cout << res << endl;
}

int main() {
	solution_4();
	return 0;
}
*/