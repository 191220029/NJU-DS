#include<iostream>
using namespace std;
int main() {
	int a, b, c, max;
	cin >> a >> b >> c;
	max = a;
	if (b > max) {
		max = b;
	}
	if (c > max)
		max = c;
	cout << max;
	/*
	int a, cnt = 1; cin >> a;
	while (a >= 10) {
		cnt++; a /= 10;
	}
	cout << cnt;
	*/
	return 0;
}