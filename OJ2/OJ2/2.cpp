/*
�ռ���ˮ
���� *N* ���Ǹ���������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��

���磬��ͼ��������������ʾ�ĸ߶�ͼ������������£������Խ� 6 ����λ����ˮ����ͼ������ɫ��ʾ����

�����ʽ
����ĵ�һ�и����������ܸ��� *N* (1 �� *N* �� 1e6)��

����ĵڶ��и������� *N* ���Ǹ��������������� 1e8�����м��ÿո������

�����ʽ
���һ���Ǹ���������ʾ���ռ�������ˮ�ĵ�λ������

��������
12
0 1 0 2 1 0 1 3 2 1 2 1
�������
6
*/

#include<iostream>
using namespace std;

long long max(long a, long b) {
	if (a > b) return a;
	return b;
}

long long min(long a, long b) {
	if (a < b)return a;
	return b;
}

void solution_2() {
	//��������;
	int N; cin >> N;
	long long* height = new long long[N];//�߶�
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	long long* maxl = new long long[N];	//��¼λ��i�������ֵ
	long long* maxr = new long long[N];	//��¼λ��i�Ҳ�����ֵ
	long long maxh = 0;
	for (int i = 0; i < N; i++) {
		maxl[i] = maxh;
		maxh = max(maxh, height[i]);
	}
	maxh = 0;
	for (int i = N - 1; i >= 0; i--) {
		maxr[i] = maxh;
		maxh = max(maxh, height[i]);
	}

	long long res = 0;
	//ͳ�ƻ�ˮ
	for (int i = 1; i < N - 1; i++) {
		long long lowermax = min(maxl[i], maxr[i]);//�ҳ�����������߸߶ȵĽ�С��
		if (height[i] < lowermax)
			res += lowermax - height[i];
	}
	cout << res << endl;
	return;
}