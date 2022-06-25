#include <iostream>
#include<string>
using namespace std;

int cnt[26];


//快速排序
void quick_sort(int* a, int left, int right) {
	if (left >= right) return;
	int i = left - 1, j = right + 1, x = a[left + right >> 1];
	while (i < j) {
		do j--; while (a[j] > x);
		do i++; while (a[i] < x);
		if (i < j) swap(a[i], a[j]);
		else quick_sort(a, left, j), quick_sort(a, j + 1, right);
	}
}

int setup(int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int first = cnt[0], second = cnt[1];

		//cout << cnt[0] << ' ' << cnt[1] << endl;

		cnt[0] = first + second;
		cnt[1] = 0x0fffffff;
		sum += cnt[0];
		quick_sort(cnt, 0, 25);

	}
	return sum;
}

int main() {
	string s; cin >> s;
	int n = 0;
	for (auto c : s) {
		cnt[c - 'A']++;
	}
	for (auto x : cnt) {//统计字母个数
		if (x != 0) n++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) cnt[i] = 0x0fffffff;
	}
	//快速排序

	quick_sort(cnt, 0, 25);


	cout << setup(n) << endl;




	return 0;
}