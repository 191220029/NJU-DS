/*
����԰

С�����ڶ�������԰���ڣ�������һ���¿�԰�ľ���԰��

����԰���ƾ����� $i$ �У�$j$��С���㣬���� $i*j$ ��С���㡣ÿ��С������������ֻè�䣨����ֻ��������ÿ��С���㣬С����ֻ�������������ϡ����ƶ���

С����ϣ����ĳһ��С���㿪ʼιè�����赱ǰС������ $n$ ֻè�䣬��ôС����ֻ���ƶ���è������ $> n$ ��С���㡣���ɴ��С�����è�������������ڵ�ǰС���㣬С�����ͻ���ʰ�������ֵػؼ��ˡ�

���ʣ�С����������ڶ��ٸ�С����ιè��

ע�⣺ֻ�������������ϡ������ĸ������ƶ�����������Խ����ƶ������磬�������Ϸ����ƶ���

ע�⣺���ھ���԰��Χ��Χǽ�����Բ����ƶ�������԰֮�⡣

��ʾ��$0 < i < 500$��$0 < j < 500$��$0 <= n < 200$��������С�����è������С�� 200��

���룺
��һ�У�����԰С���� �� i���� j
֮�� i �У�1~i��С�����Ӧ�� j �������è������

�����
ιè�������������ֵ

ʾ����

���룺
3 3
1 4 2
5 1 5
5 4 4

�����
3

��ʾ��

����԰���£����� 3 * 3 ��С���㣬�����е����ݱ�ʾÿ�������è��������

1 4 2

5 1 5

5 4 4

�����ʾ���С�����·��������1->4->5��è���������������� 3 ��С���㡣

*/

/*
#include<iostream>

using namespace std;

const int MAX_NUM = 501;

int cats[MAX_NUM][MAX_NUM];

int max_mm[MAX_NUM][MAX_NUM]; //memorize the maximum number of spaces can reach when starting from max_mm[i][j]

int I, J;

int dfs(int i, int j) {
	int cur = cats[i][j];
	int left = 0, right = 0, up = 0, down = 0;

	if (max_mm[i][j])
		return max_mm[i][j];
	else {
		if (cats[i][j - 1] > cur) left = dfs(i, j - 1);
		if (cats[i][j + 1] > cur) right = dfs(i, j + 1);
		if (cats[i + 1][j] > cur) up = dfs(i + 1, j);
		if (cats[i - 1][j] > cur) down = dfs(i - 1, j);
		int max;
		max = (left > right) ? left : right;
		max = (max > up) ? max : up;
		max = (max > down) ? max : down;

		max_mm[i][j] = max + 1;

		return max + 1;
	}

}

void solution_2() {
	cin >> I >> J;
	for (int i = 1; i <= I; i++) {
		for (int j = 1; j <= J; j++) {
			cin >> cats[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= I; i++) {
		for (int j = 1; j <= J; j++) {
			int temp = dfs(i, j);
			max = max < temp ? temp : max;
		}
	}

	cout << max << endl;

	return;
}

int main() {
	solution_2();
	return 0;
}
*/