/*
���ƽ������

A�������ɸ��������ɵĶ���������T��������нڵ��ƽ�����Ӿ���ֵ�е����ֵ��

ƽ�����ӣ� ĳ�������������ĸ߶ȼ�ȥ�������ĸ߶ȵõ��Ĳ�ֵ������һ���������������������ƽ�����Ӿ���ֵ��

����

�������룬��һ��Ϊ����Ԫ�ظ�����N<100005

�ڶ��ж������ڵ㣬������������ͼ�ж������ı�ʾ��5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1
17
					5
			4				8
	11		-1			13		4
7		2	-1	-1    -1  -1  -1  1


���

һ�������ֱ��������

����
input:
4
3 1 2 5


output:
1
*/

/*
17
5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1

9
3 1 -1 -1 2 1 -1 -1 -1
*/

/*
#include<iostream>

using namespace std;

//const int MAX_N = 100005;
int n;
//int nodes[MAX_N];
int max_be = 0;

int my_abs(int x) { return (x < 0) ? -x : x; }

int depth;

int find_max_be() {
	depth++;
	if (depth > n) return 0;
	int input; cin >> input;
	if (input == -1)return 0;

	int left_depth = find_max_be();
	int right_depth = find_max_be();

	int temp = my_abs(left_depth - right_depth);
	max_be = temp > max_be ? temp : max_be;
	return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

void solution_1() {
	cin >> n;

	find_max_be();
	cout << max_be << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}
*/