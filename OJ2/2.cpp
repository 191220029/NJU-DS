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

int main() {
	solution_2();
}
