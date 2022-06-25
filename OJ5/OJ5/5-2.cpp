/*
最强人脑

小蓝鲸受邀参加最强人脑节目。这次的项目是给出一排积木，每块积木上刻有一个字符，主持人给出一个固定的字符串，请小蓝鲸在这排积木中找到所有按字符串顺序的连续排列的积木。

输入格式

两行输入，第一行为这排积木自左向右的排列顺序，第二行输入为主持人给出的字符串。

输出格式

一行输出，自左向右列出符合要求的连续积木序列中的第一个积木所在的位置，下标从0开始计数；未找到符合的结果则输出-1。（不能输出多余的空格或回车）

数据约定

可以认为积木数量与字符串长度都不为0，且积木数量不小于字符串长度，相同字母的大小写不认为是同一字符。

输入样例
0110110
11

输出样例
1 4

*/

/*
#include<iostream>
#include<string>
using namespace std;

void getNext(string s, int next[]) {
	int j = 0, k = -1;
	int length = s.length();
	next[0] = -1; j = 1;
	while (j <= length) {
		k = next[j - 1];
		while (1) {
			if (k == -1 || s[j - 1] == s[k]) {
				k++;
				next[j] = k;
				j++;
				break;
			}
			else k = next[k];
		}
	}
}

int kmpFind(string target, string pat, int start, int next[]) {
	int posP = 0, posT = start;
	int lengthP = pat.length();
	int lengthT = target.length();

	bool kmp_succeed = false;

	//while (posP < lengthP && posT < lengthT) {
	while (posT < lengthT) {
		if (posP == -1 || pat[posP] == target[posT]) {
			posP++; posT++;
		}
		else posP = next[posP];

		if (posP == lengthP) {
			if (kmp_succeed) cout << ' ';
			cout << posT - lengthP;
			kmp_succeed = true;
			posP = next[posP];
		}
	}

	if (!kmp_succeed) cout << -1;
	cout << endl;
	//if (posP < lengthP) cout <<  -1;
	//else cout <<  posT - lengthP;
	return 0;
}

void solution_2() {
	string target, pat;
	cin >> target >> pat;
	int* nxt = new int[pat.length()+1];
	getNext(pat, nxt);
	kmpFind(target, pat, 0, nxt);
}
*/