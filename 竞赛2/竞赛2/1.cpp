/*
双基回文数

如果一个正整数 n 在二进制与十进制下都是回文数，则称 n 是双基回文数（注意：回文数不包括前导 0 ）。输入正整数 S<10e6 (十进制), 输出比 S 大的最小双基回文数。

样例输入：
20

样例输出：
33

提示：

33 十进制下是回文，二进制为 100001，也是回文。

*/

/*
#include <iostream>
#include <string>
using namespace std;


int lengthB(int x) {
	int l = 0;
	while (x != 0) {
		x >>= 1;
		l++;
	}
	return l;
}

int getbyte(int x, int pos) {
	return (x >> pos) & 0x1;
}

bool isDh(int x) {
	string s = to_string(x);
	int front = 0; int rear = s.length() - 1;
	while (front < rear) {
		if (s[front] != s[rear]) return false;
		front++;
		rear--;
	}
	return true;
}

bool isBh(int x, const int& length) {
	int front = 0, rear = length - 1;
	while (front < rear) {
		if (getbyte(x, front) != getbyte(x, rear)) return false;
		front++;
		rear--;
	}
	return true;
}

void solution_1() {
	int x; cin >> x;
	x++;
	int lb = lengthB(x);
	//cout << ld << endl;
	//cout << lb << endl;
	while (!(isDh(x) && isBh(x, lb))) {
		x++;
		lb = lengthB(x);
	}
	cout << x << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}

*/