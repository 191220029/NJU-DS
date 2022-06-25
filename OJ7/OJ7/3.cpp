/*
麻将对胡

小蓝鲸和朋友一起打麻将（一种特殊的麻将）。他定睛一看，这牌貌似可以打对胡，但是现在牌摆放顺序散乱不太容易辨别。假设此时他手中有N对牌（即共2N张），所有牌用0
0
到2N−1
2N−1
表示，其中{2k,2k+1}
{2k,2k+1}
为一对相同图案的牌，k∈[0,N−1]
k∈[0,N−1]
。小蓝鲸每次可以交换两张麻将的位置，请问至少交换几次可以将对胡的牌型摆放好。

注：这种特殊的麻将有很多种图案（并非传统麻将42种图案）；对胡牌型摆放好的标准可以认为是每一对相同图案的牌都相邻摆，放比如0123
0123
中{0,1}
{0,1}
摆放在一起，{2,3}
{2,3}
摆放在一起（因此3201
3201
亦可认为是摆放好的一种对胡牌型）。

输入格式

两行输入，第一行是一个正整数N，第二行输入为0到N-1，N个自然数的一种排列。

输出格式

一行输出，直接输出最少的交换麻将位置的次数。

输入样例
4
0 2 1 3

输出样例
1

解释：将2和1交换位置即可（交换0和3亦可）

*/

/*

#include<iostream>
using namespace std;

int normalize(int *a, int length) {
	int cnt = 0;
	for (int i = 0; i < length;) { //扫描所有的排找到其对应的对子
		if (a[i] % 2 == 0) { //遇到2k
			if (a[i + 1] == a[i] + 1) {//i, i+1是对子
				i += 2;
			}
			else { //不是对子
				//向后寻找对子
				int j = i + 1;
				for (; j < length; j++) {
					if (a[j] == a[i] + 1) break;
				}
				//swap a[j], a[i+1]
				int temp = a[j]; a[j] = a[i + 1]; a[i + 1] = temp;
				i += 2;
				cnt++;
			}
		}
		else { //遇到2k+1 向后寻找对子
			if (a[i + 1] == a[i] - 1) {//i, i+1是对子
				i += 2;
			}
			else {
				int j = i + 1;

				for (; j < length; j++) {
					if (a[j] == a[i] - 1)break;
				}
				int temp = a[j]; a[j] = a[i + 1]; a[i + 1] = temp;
				i += 2;
				cnt++;
			}

		}
	}
	return cnt;
}

void solution_1() {
	int N; cin >> N;
	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int cnt = normalize(a, N);
	cout << cnt << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}*/